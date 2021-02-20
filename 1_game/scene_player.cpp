//========================================
// scene_player.cpp
//========================================
#include "scene_player.hpp"
#include "scene_game.hpp"

#include "player_x.hpp"
#include "player_r.hpp"

//----------------------------------------
// SCENE_PLAYER
//----------------------------------------
using namespace opal;

//----------------------------------------
//
//----------------------------------------
void SCENE_PLAYER::Init( const char* p ){

	RESOURCE::PLAYER::SysInit();

	WORKL::Init( p );

	PRIMS::MakeSharedPrim( player );
	player->SetTexture( RESOURCE::PLAYER::Texture() );

	Game::AtariRegister( "PLAYER", player );
}

void SCENE_PLAYER::Free( void ){

	player = nullptr;

	WORKL::Free();

	RESOURCE::PLAYER::SysFree();
}

void SCENE_PLAYER::ObjFunc( void ){}

//----------------------------------------
//----------------------------------------
auto SCENE_PLAYER::GetConnect( void ) const->const ACTOR_X*{ return player.get();	}

//----------------------------------------
//
//----------------------------------------
void SCENE_PLAYER::SetPosition( int x, int y ){

	Game::SetPosition( player, x, y );
}

void SCENE_PLAYER::SetDirection( int d ){

	Game::SetDirection( player, d );
}

// End Of File
