//========================================
// scene_player.cpp
//========================================
#include "scene_player.hpp"
#include "scene_game.hpp"

#include "player_x.hpp"
#include "player_r.hpp"

#include "constant.hpp"

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
	{
		player->SetTexture( RESOURCE::PLAYER::Texture() );

		player->SetMoveSpeed(  CONSTANT::PLAYER_MOVE_SPEED  );
		player->SetTurnSpeed(  CONSTANT::PLAYER_TURN_SPEED  );
		player->SetSpellSpeed( CONSTANT::PLAYER_SPELL_SPEED );
		player->SetSpellPower( CONSTANT::PLAYER_SPELL_POWER );
		player->SetSpellPivot( CONSTANT::PLAYER_SPELL_PIVOT );
	}

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

	player->SetPosition();
}

void SCENE_PLAYER::SetDirection( int d ){

	Game::SetDirection( player, d );

	player->SetDirection();
}

// End Of File
