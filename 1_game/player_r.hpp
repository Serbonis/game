#pragma once
//========================================
// player_r.hpp
//========================================
#include "resource.hpp"
#include "player_k.hpp"

//----------------------------------------
// RESOURCE - PLAYER
//----------------------------------------
namespace RESOURCE::PLAYER {
	extern void SysInit( void );
	extern void SysFree( void );
}

namespace RESOURCE::PLAYER {
	extern auto Texture( void )->TEXTURE*;
	extern auto Texture( PLAYER_KIND )->TEXTURE*;
}

// End Of File
