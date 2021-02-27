//========================================
// scene_game.cpp
//========================================
#include "scene_game.hpp"

#include "scene_atari.hpp"
#include "scene_camera.hpp"
#include "scene_player.hpp"
#include "scene_enemy.hpp"
#include "scene_spell.hpp"
#include "scene_grid.hpp"

//----------------------------------------
// VIEW PORT
//----------------------------------------
//----------------------------------------
// SCENE GAME
//----------------------------------------
using namespace opal;
using namespace SCENE_GAME;

namespace {
	SCENE_G*	game;
}

#if OPAL_DEBUG
static bool	debug_flag;
#endif

#include "draw.hpp"

struct VIEWPORT {
	void operator()( const SRECTF& v                    ){ begin.SetRect( v ); 				}
	void operator()( float x, float y, float w, float h ){ begin.SetRect( x, y, w, h );		}
	void operator()( const VECTOR2& p, float w, float h ){ begin.SetRect( p.x, p.y, w, h );	}
	void operator()( float x, float y, const SSIZE& s   ){ begin.SetRect( x, y, s.w, s.h );	}

	class BEGIN final :
		public opal::DRAWT,
		public opal::CRECTF
	{
	private:
		virtual void DrawMain( void ) override { DRAWX::ViewportBegin( *this ); }
	}	begin;

	class END final : public opal::DRAWT {
	private:
		virtual void DrawMain( void ) override { DRAWX::ViewportEnd(); }
	}	end;
};

VIEWPORT	viewport;

struct SCISSOR {
	void operator()( const SRECTF& v                    ){ begin.SetRect( v ); 				}
	void operator()( float x, float y, float w, float h ){ begin.SetRect( x, y, w, h );		}
	void operator()( const VECTOR2& p, float w, float h ){ begin.SetRect( p.x, p.y, w, h );	}
	void operator()( float x, float y, const SSIZE& s   ){ begin.SetRect( x, y, s.w, s.h );	}

	class BEGIN final :
		public opal::DRAWT,
		public opal::CRECTF
	{
	private:
		virtual void DrawMain( void ) override { DRAWX::SetScissor( *this ); }
	}	begin;

	class END final : public opal::DRAWT {
	private:
		virtual void DrawMain( void ) override { DRAWX::SetScissor(); }
	}	end;
};

SCISSOR	scissor;

//----------------------------------------
// 初期化
//----------------------------------------
SCENE_G::SCENE_G() :
	step{0},
	level{0},
	size{0,0},
	atari{ std::make_shared<SCENE_ATARI>() },
	camera{std::make_shared<SCENE_CAMERA>()},
	player{std::make_shared<SCENE_PLAYER>()},
	enemy{ std::make_shared<SCENE_ENEMY>() },
	spell{ std::make_shared<SCENE_SPELL>() },
	grid{  std::make_shared<SCENE_GRID>()  }
{
	game	= this;

	atari->Open(  "ATARI"  );
	camera->Open( "CAMERA" );

	viewport.begin.Open( "VP GAME" );
	viewport( -200, 0, 1600, 1200 );
	scissor.begin.Open( "SC GAME" );
	scissor( 0, 400, 1600-400, 1200 );
	{
		player->Open( "PLAYER" );
		enemy->Open(  "ENEMY"  );
		spell->Open(  "SPELL"  );
		grid->Open(   "GRID"   );
	}
	viewport.end.Open( "VP GAME" );
	viewport.end.SetPrio( 1 );
	scissor.end.Open( "SC GAME" );
	scissor.end.SetPrio( 1 );

	camera->SetConnect( player->GetConnect() );

#if OPAL_DEBUG
	debug_flag = true;
#endif
}

//----------------------------------------
// 後始末
//----------------------------------------
SCENE_G::~SCENE_G()
{
	scissor.end.Close();
	viewport.end.Close();
	{
		grid->Close();
		spell->Close();
		enemy->Close();
		player->Close();
	}
	scissor.begin.Close();
	viewport.begin.Close();

	camera->Close();
	atari->Close();

	game = nullptr;
}

//----------------------------------------
// 実行
//----------------------------------------
#if OPAL_DEBUG
#include "controll.hpp"
#endif
bool SCENE_G::operator()( SCENE_MANAGER* ){

	switch ( step ) {
	case 0:
		GenerateMap( level );
		step++;
		break;

	case 1:
		if ( CONTROLL::RestartMap() ) {
			level = (level+1)%2;
			DestroyMap();
			step = 0;
		}
		break;
	}

#if OPAL_DEBUG
	if ( CONTROLL::GameDebug() ) {
		FLAG_CTRL( debug_flag, FLAG_FLIP );
	}

	if ( debug_flag ) {
		printd( "========================================\n" );
		printd( "= GAME\n" );
		printd( "========================================\n" );
		printd( "LEVEL : %d\n", level );
		printd( "SIZE  : %02d %02d\n", size.w, size.h );
		printd( "\n" );
	}
#endif

	return false;
}

//----------------------------------------
// マップ生成
//----------------------------------------
#include "map_data.hpp"

void SCENE_G::GenerateMap( int n ){

	if ( 0 <= n && n < ( int )map_data_max ) {
		if ( const auto m = map_data[n]; m ) {
			size = { m->map.size };

			layout_grid( m );
			layout_player( m );
			layout_enemy( m );
			layout_item( m );
		}
	}
}

// MAP
void SCENE_G::layout_grid( const MAP_DATA* m ){

	[[maybe_unused]]const auto	[ox,oy] = m->map.offset;

	grid->Generate( size.w, size.h );

	for ( auto i = 0UL; i < size.h; i++ ) {
		for ( auto j = 0UL; j < size.w; j++ ) {
			const auto	g = m->GridData( j, i );

			grid->SetPosition( j, i );
			grid->SetFloor( j, i, g->f );
			grid->SetCeil(  j, i, g->c );
			for ( auto d = 0UL; d < DIX_MAX; d++ ) {
				grid->SetWall( j, i, ( DIX )d, g->w[d] );
			}
		}
	}
}

// PLAYER
void SCENE_G::layout_player( const MAP_DATA* m ){

	const auto	[x,y] = m->player.start;

	player->SetPosition( x, y );
	camera->SetPosition( x, y );

	const auto	d = m->player.direction;

	player->SetDirection( d );
	camera->SetDirection( d );
}

// ENEMY
void SCENE_G::layout_enemy( const MAP_DATA* m ){

	const auto	en = m->enemy.number;
	for ( auto i = 0UL; i < en; i++ ) {
		const auto	d = &m->enemy.data[i];
		const auto	e = enemy->Generate( d->kind );
		const auto	[x,y] = d->position;

		enemy->SetPosition(  e, x, y );
		enemy->SetDirection( e, d->direction );
		enemy->SetStatus(    e, d->stat );
	}
}

// ITEM
void SCENE_G::layout_item( const MAP_DATA* m ){}

//----------------------------------------
// マップ破棄
//----------------------------------------
void SCENE_G::DestroyMap( void ){

	grid->Destroy();
	spell->Destroy();
	enemy->Destroy();
}

//----------------------------------------
// Game
//----------------------------------------
//----------------------------------------
//----------------------------------------
auto SCENE_G::GridSize( void )->float{ return GRID_SIZE;	}
auto SCENE_G::MapSize( void )->SSIZE2U{ return game->size;	}

//----------------------------------------
// マップデータをマップ位置に変換
//----------------------------------------
auto SCENE_G::Data2Map( int x, int y, float h )->VECTOR3{

	const auto	s = GridSize();
	const auto	m = MapSize();

	return { ( ( 0   +   x ) + 0.5f ) * s,
			 h,
			 ( ( m.h-1 - y ) + 0.5f ) * s };
}

//----------------------------------------
//----------------------------------------
// マップ位置をオブジェクト座標に変換
auto SCENE_G::MapVector( const POINT2I& p, float y )->VECTOR3{

	const auto	s = GridSize();
	const auto	x = ( p.x + 0.5f ) * s;
	const auto	z = ( p.y + 0.5f ) * s;

	return { x, y, z };
}

// オブジェクト座標からマップ位置内のオフセットを算出
auto SCENE_G::MapOffset( const opal::VECTOR3& t )->opal::DVECTOR{ return { MapOffset( t.x, t.z ),t.y };}
auto SCENE_G::MapOffset( float x, float z )->opal::VECTOR2{ return { MapOffsetX( x ), MapOffsetY( z ) };}
auto SCENE_G::MapOffsetX( float p )->float{ return std::fmod( p, +GridSize() );	}
auto SCENE_G::MapOffsetY( float p )->float{ return std::fmod( p, -GridSize() );	}

//----------------------------------------
//----------------------------------------
// オブジェクトの座標をマップ位置に変換
auto SCENE_G::MapPosition( const VECTOR3& v )->POINT2I{

	const auto	s = GridSize();
	const auto	x = ( int )( v.x/s );
	const auto	y = ( int )( v.z/s );

	return { v.x < 0 ? x-1 : x,
			 v.z < 0 ? y-1 : y };
}

// オブジェクトの回転をマップ方向に変換
auto SCENE_G::MapDirection( float r )->int{

	return int( r/ RAD( 90.f ) ) % DIX_MAX;
}

//----------------------------------------
//----------------------------------------
void SCENE_G::SetPosition( std::shared_ptr<OBJECT> o, int x, int y ){

	const auto	p = Data2Map( x, y );

	o->SetTransX( p.x );
	o->SetTransZ( p.z );
}

void SCENE_G::SetDirection( std::shared_ptr<OBJECT> o, int d ){

	o->SetRotate( Dix2Rad( d ) );
}

//----------------------------------------
//----------------------------------------
bool SCENE_G::GenerateSpell( const SPELL_DATA& d ){

	return game->spell->Generate( d ) ? true : false;
}

//----------------------------------------
//----------------------------------------
void SCENE_G::AtariRegister( const char* s, std::shared_ptr<ACTOR_X> p ){ game->atari->AtariRegister( s, p );	}
void SCENE_G::AtariRelease(  const char* s, std::shared_ptr<ACTOR_X> p ){ game->atari->AtariRelease(  s, p );	}

// End Of File
