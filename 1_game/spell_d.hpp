#pragma once
//========================================
// spell_d.hpp
//========================================
#include "com.hpp"
#include "spell_k.hpp"

//----------------------------------------
// DATA - SPELL
//----------------------------------------
namespace DATA_SPELL {
	extern auto SpellName( SPELL_KIND )->std::string;

	extern auto SpellKind( const std::string& )->SPELL_KIND;

	extern auto SpellKind( void )->SPELL_KIND;
}

//----------------------------------------
// SPELL DATA
//----------------------------------------
struct SPELL_DATA {
	SPELL_KIND	kind;
	float		power;
	float		speed;
	float		posx,posy;
	float		height;
	float		direction;
};

// End Of File
