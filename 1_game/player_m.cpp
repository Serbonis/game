//========================================
// player_m.cpp
//========================================
#include "player_m.hpp"

#include "scene_game.hpp"

//----------------------------------------
// PLAYER M
//----------------------------------------
using namespace opal;

//----------------------------------------
// constructor & destructor
//----------------------------------------

//----------------------------------------
//----------------------------------------
auto PLAYER_M::Kind( void ) const->PLAYER_KIND{ return kind;	}

//----------------------------------------
//----------------------------------------
void PLAYER_M::SetName( const std::string& s ){ name = s;	}
void PLAYER_M::SetName( void ){ name = "";	}
auto PLAYER_M::GetName( void ) const->std::string{ return name;	}

//----------------------------------------
//----------------------------------------
void PLAYER_M::SetPlayerParam( const PLAYER_PARAM& p ){

	hp_val	= p.hp.val;
	hp_max	= p.hp.max;
	mp_val	= p.mp.val;
	mp_max	= p.mp.max;

	move 	= p.move;
	turn 	= p.turn;
	jump 	= p.jump;
}

auto PLAYER_M::GetPlayerParam( void ) const->PLAYER_PARAM{

	return {{hp_val,hp_max},
			{mp_val,mp_max},
			move,turn,jump};
}

//----------------------------------------
//----------------------------------------
void PLAYER_M::SetMoveSpeed( float s ){ move.speed = s;	}
auto PLAYER_M::GetMoveSpeed( void ) const->float{ return move.speed;	}
void PLAYER_M::SetTurnSpeed( float s ){ turn.speed = s;	}
auto PLAYER_M::GetTurnSpeed( void ) const->float{ return turn.speed;	}
void PLAYER_M::SetJumpSpeed( float s ){ jump.speed = s;	}
auto PLAYER_M::GetJumpSpeed( void ) const->float{ return jump.speed;	}

//----------------------------------------
//----------------------------------------
#include "spell_k.hpp"
#include "spell_d.hpp"

void PLAYER_M::Spell( SPELL_KIND k, float p, float s, float x, float y, float h, float r ){

	Game::GenerateSpell( SPELL_DATA{k,p,s,x,y,h,r} );
}


// End Of File
