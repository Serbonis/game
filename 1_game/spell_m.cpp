//========================================
// spell_m.cpp
//========================================
#include "spell_m.hpp"

//----------------------------------------
// SPELL M
//----------------------------------------
using namespace opal;

//----------------------------------------
// constructor & destructor
//----------------------------------------

//----------------------------------------
//----------------------------------------
auto SPELL_M::Kind( void ) const->SPELL_KIND{ return kind;	}

//----------------------------------------
//----------------------------------------
void SPELL_M::SetPower( float p ){ power = p;	}
void SPELL_M::SetSpeed( float s ){ speed = s;	}

auto SPELL_M::GetPower( void ) const->float{ return power;	}
auto SPELL_M::GetSpeed( void ) const->float{ return speed;	}

// End Of File
