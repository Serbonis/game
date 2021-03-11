#pragma once
//========================================
// player_p.hpp
//========================================
#include "actor_p.hpp"

//----------------------------------------
//----------------------------------------
struct PLAYER_PARAM {
	PARAMETER::VALMAX	hp;
	PARAMETER::VALMAX	mp;

	PARAMETER::MOVE		move;
	PARAMETER::TURN		turn;
	PARAMETER::JUMP		jump;
};

// End Of File
