#pragma once
//========================================
// player.hpp
//========================================
#include "com.hpp"

#include "player_k.hpp"
#include "player_d.hpp"

//----------------------------------------
// PLAYER
//----------------------------------------
struct PLAYER {
	PLAYER( PLAYER_KIND k = PLAYER_KIND::Undef ) : kind{k}{}
	~PLAYER() = default;

	const PLAYER_KIND	kind;
	std::string			name;
};

// End Of File
