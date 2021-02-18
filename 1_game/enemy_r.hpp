#pragma once
//========================================
// enemy_r.hpp
//========================================
#include "resource.hpp"
#include "enemy_k.hpp"

//----------------------------------------
// RESOURCE - ENEMY
//----------------------------------------
namespace RESOURCE::ENEMY {
	extern void SysInit( void );
	extern void SysFree( void );
}

namespace RESOURCE::ENEMY {
	extern auto Texture( ENEMY_KIND )->TEXTURE*;
}

// End Of File
