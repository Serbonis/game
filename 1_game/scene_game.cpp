//========================================
// scene_game.cpp
//========================================
#include "scene_game.hpp"

#include "scene_camera.hpp"
#include "scene_player.hpp"
#include "scene_enemy.hpp"
#include "scene_spell.hpp"
#include "scene_grid.hpp"

#include "atari.hpp"

//----------------------------------------
// SCENE GAME
//----------------------------------------
using namespace opal;
using namespace SCENE_GAME;

namespace {
	SCENE_G*	game;
}

//----------------------------------------
// 初期化
//----------------------------------------
SCENE_G::SCENE_G() :
	step{0},
	size{0,0},
	camera{std::make_shared<SCENE_CAMERA>()},
	player{std::make_shared<SCENE_PLAYER>()},
	enemy{ std::make_shared<SCENE_ENEMY>() },
	spell{ std::make_shared<SCENE_SPELL>() },
	grid{  std::make_shared<SCENE_GRID>()  }
{
	game	= this;

	atari = std::shared_ptr<ATARIS>( SRVCS::Generate<ATARIS>( "ATARI" ), [](auto){ SRVCS::Destroy( "ATARI" ); } );
	atari->Begin();
	atari->Create( "P_SHOT","E_SHOT" );
	atari->Create( "P_SHOT","ENEMY"  );
	atari->Create( "PLAYER","ENEMY"  );
	atari->Create( "PLAYER","E_SHOT" );

	camera->Open( "CAMERA" );
	player->Open( "PLAYER" );
	enemy->Open( "ENEMY" );
	spell->Open( "SPELL" );
	grid->Open( "GRID" );

	camera->SetConnect( player->GetConnect() );
}

//----------------------------------------
// 後始末
//----------------------------------------
SCENE_G::~SCENE_G()
{
	grid->Close();
	spell->Close();
	enemy->Close();
	player->Close();
	camera->Close();

	atari->Destroy();
	atari->End();
	atari = nullptr;
}

//----------------------------------------
// 実行
//----------------------------------------
bool SCENE_G::operator()( SCENE_MANAGER* ){

	atari->Debug();

	switch ( step ) {
	case 0:
		GenerateMap();
		step++;
		break;

	case 1:
		if ( PADX::KeyTrig( KEY_P ) ) {
			DestroyMap();
			step = 0;
		}
		break;
	}

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

auto SCENE_G::MapPoint( const VECTOR3& v )->POINT2I{

	const auto	s = GridSize();
	const auto	x = ( int )( v.x/s );
	const auto	y = ( int )( v.z/s );

	return { v.x < 0 ? x-1 : x,
			 v.z < 0 ? y-1 : y };
}

auto SCENE_G::MapVector( const POINT2I& p, float y )->VECTOR3{

	const auto	s = GridSize();
	const auto	x = ( p.x + 0.5f ) * s;
	const auto	z = ( p.y + 0.5f ) * s;

	return { x, y, z };
}

auto SCENE_G::MapPosition( int x, int y, float h )->VECTOR3{

	const auto	s = GridSize();
	const auto	m = MapSize();

	return { ( ( 0   +   x ) + 0.5f ) * s,
			 h,
			 ( ( m.h-1 - y ) + 0.5f ) * s };
}

//----------------------------------------
//----------------------------------------
void SCENE_G::SetPosition( std::shared_ptr<OBJECT> o, int x, int y ){

	const auto	p = MapPosition( x, y );

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
#include "actor_x.hpp"

void SCENE_G::AtariRegister( const char* s, std::shared_ptr<ACTOR_X> p ){ game->atari->Register( s, p );	}
void SCENE_G::AtariRelease(  const char* s, std::shared_ptr<ACTOR_X> p ){ game->atari->Release(  s, p );	}

// End Of File
