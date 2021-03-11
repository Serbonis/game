#pragma once
//========================================
// spell_r.hpp
//========================================
#include "resource.hpp"
#include "spell_k.hpp"

//----------------------------------------
// RESOURCE - SPELL
//----------------------------------------
namespace RESOURCE::SPELL {
	extern void SysInit( void );
	extern void SysFree( void );
}

namespace RESOURCE::SPELL {
	extern auto Texture( SPELL_KIND, UINT = 0 )->TEXTURE*;
}

// End Of File
