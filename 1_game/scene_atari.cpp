//========================================
// scene_atari.cpp
//========================================
#include "scene_atari.hpp"
#include "scene_game.hpp"

//----------------------------------------
// SCENE_ATARI
//----------------------------------------
using namespace opal;

//----------------------------------------
//
//----------------------------------------
void SCENE_ATARI::Init( const char* p ){

	WORKL::Init( p );

	server = std::shared_ptr<ATARIS>( SRVCS::Generate<ATARIS>( "ATARI" ), [](auto){ SRVCS::Destroy( "ATARI" ); } );
	server->Begin();
	server->Create( "P_SHOT","E_SHOT" );
	server->Create( "P_SHOT","ENEMY"  );
	server->Create( "PLAYER","ENEMY"  );
	server->Create( "PLAYER","E_SHOT" );
}

void SCENE_ATARI::Free( void ){

	server->Destroy();
	server->End();
	server = nullptr;

	WORKL::Free();
}

void SCENE_ATARI::ObjFunc( void ){

	server->Debug();
}

#include "actor_x.hpp"

void SCENE_ATARI::AtariRegister( const char* s, std::shared_ptr<ACTOR_X> p ){ server->Register( s, p );	}
void SCENE_ATARI::AtariRelease(  const char* s, std::shared_ptr<ACTOR_X> p ){ server->Release(  s, p );	}

// End Of File
