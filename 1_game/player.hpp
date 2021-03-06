#pragma once
//========================================
// player.hpp
//========================================
#include "com.hpp"
#include "player_k.hpp"
#include "player_d.hpp"
#include "player_p.hpp"

//----------------------------------------
// PLAYER
//----------------------------------------
struct PLAYER {
	PLAYER( PLAYER_KIND k = PLAYER_KIND::Undef ) : kind{k}{}
	~PLAYER() = default;

	const PLAYER_KIND	kind;
	std::string			name;

	PARAMETER::MOVE		move;
	PARAMETER::TURN		turn;
	PARAMETER::JUMP		jump;
};

// End Of File
