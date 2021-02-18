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

	camera->Open();
	camera->SetArmV( +s/2 );
	camera->SetArmH( -s/2 );
	camera->Parent( platform );

	DRAWX::Camera( (*camera)() );
}

void SCENE_CAMERA::Free( void ){

	if ( camera ) {
		camera->Close();
	}
	camera = nullptr;

	if ( platform ) {
		platform->Close();
	}
	platform = nullptr;

	WORKL::Free();
}

void SCENE_CAMERA::ObjFunc( void ){}

//----------------------------------------
//----------------------------------------
void SCENE_CAMERA::SetConnect( const ACTOR_X* a ){ platform->SetConnect( a );	}

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
