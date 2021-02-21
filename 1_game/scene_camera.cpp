//========================================
// scene_camera.cpp
//========================================
#include "scene_camera.hpp"
#include "scene_game.hpp"

#include "camera_x.hpp"
#include "camera_p.hpp"

//----------------------------------------
// SCENE_CAMERA
//----------------------------------------
using namespace opal;

//----------------------------------------
//
//----------------------------------------
void SCENE_CAMERA::Init( const char* p ){

	WORKL::Init( p );

	makeshared( platform );
	platform->Open();

	makeshared( camera );

	const auto	s = Game::GridSize();

	camera->Open( "MAIN" );
	camera->SetArmV( +s/2 );
	camera->SetArmH( -s/2 );
	camera->Parent( platform );

	DRAWX::Camera( (*camera)() );

	makeshared( handy );

	handy->Open( "HANDY" );
	handy->SetTilt( RAD( 90.f ) );
	handy->SetArmV( s * 8 );
	handy->Parent( platform );

	number = 0;
}

void SCENE_CAMERA::Free( void ){

	if ( handy  ) { handy->Close();  } handy  = nullptr;
	if ( camera ) { camera->Close(); } camera = nullptr;

	if ( platform ) {
		platform->Close();
	}
	platform = nullptr;

	WORKL::Free();
}

//----------------------------------------
//----------------------------------------
#if OPAL_DEBUG
#include "controll.hpp"
#endif
void SCENE_CAMERA::ObjFunc( void ){
#if OPAL_DEBUG
	if ( CONTROLL::CameraChange() ) {
		SetCamera();
	}

	if ( CONTROLL::CameraDebug() ) {
		switch ( number ) {
		case 0: camera->Debug();	break;
		case 1: handy->Debug();		break;
		}
	}
#endif
}

//----------------------------------------
//----------------------------------------
void SCENE_CAMERA::SetConnect( const ACTOR_X* a ){ platform->SetConnect( a );	}

//----------------------------------------
//----------------------------------------
void SCENE_CAMERA::SetCamera( UINT n ){

	if ( n <= 1 ) {
		switch ( number = n ) {
		case 0: DRAWX::Camera( (*camera)() );	break;
		case 1: DRAWX::Camera( (*handy)() );	break;
		}
	}
}

void SCENE_CAMERA::SetCamera( void ){

	SetCamera( number ? 0 : 1 );
}

auto SCENE_CAMERA::GetCamera( void ) const->UINT{ return number;	}

//----------------------------------------
//
//----------------------------------------
void SCENE_CAMERA::SetPosition( int x, int y ){

	Game::SetPosition( platform, x, y );

	*platform = Game::MapPoint( Game::MapPosition( x, y ) );
}

void SCENE_CAMERA::SetDirection( int d ){

	Game::SetDirection( platform, d );
}

// End Of File
