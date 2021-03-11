//========================================
// scene_game.cpp
//========================================
#include "scene_game.hpp"

#include "scene_atari.hpp"
#include "scene_camera.hpp"
#include "scene_object.hpp"

#include "player_d.hpp"
#include "player_r.hpp"

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

//----------------------------------------
// 初期化
//----------------------------------------
SCENE_G::SCENE_G() :
	step{0},
	level{0},
	size{0,0},
	frame{ std::make_shared<SCENE_FRAME>() },
	atari{ std::make_shared<SCENE_ATARI>() },
	camera{std::make_shared<SCENE_CAMERA>()},
	object{std::make_shared<SCENE_OBJECT>()}
{
	game	= this;

	frame->Open(  "FRAME"  );
	atari->Open(  "ATARI"  );
	camera->Open( "CAMERA" );
	object->Open( "OBJECT" );

	frame->SetObject( object );

#if OPAL_DEBUG
	debug_flag = true;
#endif
	{
		const UINT	id = 0;
		const auto	player = object->player;

		player->Generate( id );
		player->SetName( id, "SAMPLE" );
		frame->SetActor( id, player->GetConnect( id ) );
		frame->GenerateStatus( id );
		frame->StatusName(  id, player->GetName( id ) );
		frame->StatusFace(  id, RESOURCE::PLAYER::TextureFace() );
	}
}

//----------------------------------------
// 後始末
//----------------------------------------
SCENE_G::~SCENE_G()
{
	object->Close();
	camera->Close();
	atari->Close();
	frame->Close();

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
		BeginLevel( level );
		step++;
		break;

	case 1:
		if ( CONTROLL::RestartMap() ) {
			level = (level+1)%2;
			EndLevel();
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
// Game
//----------------------------------------
//----------------------------------------
//----------------------------------------
#include "map_data.hpp"

void SCENE_G::BeginLevel( int n ){

	if ( 0 <= n && n < ( int )map_data_max ) {
		if ( const auto m = map_data[n]; m ) {
			size = { m->map.size };

			object->GenerateMap( m );

			const auto	[x,y] = m->player.start;
			const auto	d = m->player.direction;

			camera->ObjPosition( x, y );
			camera->ObjDirection( d );
		}
	}

	camera->SetConnect( object->player->GetConnect( 0 ) );

	frame->GenerateMinimap();
	frame->GenerateRadar();
}

void SCENE_G::EndLevel( void ){

	frame->DestroyRadar();
	frame->DestroyMinimap();

	object->DestroyMap();
}

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
void SCENE_G::ObjPosition( std::shared_ptr<OBJECT> o, int x, int y ){

	const auto	p = Data2Map( x, y );

	o->SetTransX( p.x );
	o->SetTransZ( p.z );
}

void SCENE_G::ObjDirection( std::shared_ptr<OBJECT> o, int d ){

	o->SetRotate( Dix2Rad( d ) );
}

//----------------------------------------
//----------------------------------------
bool SCENE_G::GenerateSpell( const SPELL_DATA& d ){

	return game->object->GenerateSpell( d ) ? true : false;
}

//----------------------------------------
//----------------------------------------
void SCENE_G::AtariRegister( const char* s, std::shared_ptr<ACTOR_X> p ){ game->atari->AtariRegister( s, p );	}
void SCENE_G::AtariRelease(  const char* s, std::shared_ptr<ACTOR_X> p ){ game->atari->AtariRelease(  s, p );	}

// End Of File
