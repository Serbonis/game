#pragma once
//========================================
// spell_m.hpp
//========================================
#include "spell.hpp"

//----------------------------------------
// SPELL M
//----------------------------------------
class SPELL_M : protected SPELL {
	using SPELL::SPELL;

public:
	virtual auto Kind( void ) const->SPELL_KIND final;

public:
	virtual void SetPower( float );
	virtual void SetSpeed( float );
	virtual auto GetPower( void ) const->float;
	virtual auto GetSpeed( void ) const->float;
};

// End Of File
