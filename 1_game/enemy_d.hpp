#pragma once
//========================================
// enemy_d.hpp
//========================================
#include "com.hpp"
#include "enemy_k.hpp"

//----------------------------------------
// DATA - ENEMY
//----------------------------------------
namespace DATA_ENEMY {
	extern auto EnemyName( ENEMY_KIND )->std::string;

	extern auto EnemyKind( const std::string& )->ENEMY_KIND;

	extern auto EnemyKind( void )->ENEMY_KIND;
}

// End Of File
