#pragma once
//========================================
// player_m.hpp
//========================================
#include "player.hpp"

//----------------------------------------
// PLAYER M
//----------------------------------------
enum class SPELL_KIND;

class PLAYER_M : protected PLAYER {
	using PLAYER::PLAYER;

public:
	virtual auto Kind( void ) const->PLAYER_KIND final;

public:
	virtual void Spell( SPELL_KIND, float, float, float, float, float, float ) final;
};

// End Of File
