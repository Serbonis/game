#pragma once
//========================================
// enemy_m.hpp
//========================================
#include "enemy.hpp"

//----------------------------------------
// ENEMY M
//----------------------------------------
class ENEMY_M : protected ENEMY {
	using ENEMY::ENEMY;

public:
	virtual auto Kind( void ) const->ENEMY_KIND final;
};

// End Of File
