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
	extern auto TextureBody( void )->TEXTURE*;
	extern auto TextureFace( void )->TEXTURE*;
	extern auto TextureBody( PLAYER_KIND )->TEXTURE*;
	extern auto TextureFace( PLAYER_KIND )->TEXTURE*;
}

// End Of File
