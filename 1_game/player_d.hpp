#pragma once
//========================================
// player_d.hpp
//========================================
#include "com.hpp"
#include "player_k.hpp"
#include "player_p.hpp"

//----------------------------------------
// DATA - PLAYER
//----------------------------------------
namespace DATA_PLAYER {
	extern const float	PLAYER_MOVE_SPEED;
	extern const float	PLAYER_TURN_SPEED;
	extern const float	PLAYER_JUMP_SPEED;
	extern const float	PLAYER_SPELL_SPEED;
	extern const float	PLAYER_SPELL_POWER;
	extern const float	PLAYER_SPELL_PIVOT;
}

namespace DATA_PLAYER {
	extern auto PlayerName( PLAYER_KIND )->std::string;
	extern auto PlayerParam( PLAYER_KIND )->PLAYER_PARAM;
}

// End Of File
