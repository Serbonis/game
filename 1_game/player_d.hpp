#pragma once
//========================================
// player_d.hpp
//========================================
#include "com.hpp"
#include "player_k.hpp"

//----------------------------------------
// DATA - PLAYER
//----------------------------------------
namespace DATA_PLAYER {
	extern auto PlayerName( PLAYER_KIND )->std::string;

	extern auto PlayerKind( const std::string& )->PLAYER_KIND;

	extern auto PlayerKind( void )->PLAYER_KIND;
}

// End Of File
