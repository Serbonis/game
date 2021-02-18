#pragma once
//========================================
// spell.hpp
//========================================
#include "com.hpp"

#include "spell_k.hpp"
#include "spell_d.hpp"

//----------------------------------------
// SPELL
//----------------------------------------
struct SPELL {
	SPELL( SPELL_KIND k ) : kind{k}{}
	~SPELL() = default;

	const SPELL_KIND	kind;
	std::string			name;

	float	power;
	float	speed;
};

// End Of File
