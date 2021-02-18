#pragma once
//========================================
// grid_r.hpp
//========================================
#include "resource.hpp"
#include "grid_k.hpp"

//----------------------------------------
// RESOURCE - GRID
//----------------------------------------
namespace RESOURCE::GRID {
	extern void SysInit( void );
	extern void SysFree( void );
}

namespace RESOURCE::GRID {
	extern auto Texture( GRID_KIND_FLOOR )->TEXTURE*;
	extern auto Texture( GRID_KIND_CEIL  )->TEXTURE*;
	extern auto Texture( GRID_KIND_WALL  )->TEXTURE*;
}

// End Of File
