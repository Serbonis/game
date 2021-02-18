//========================================
// spell_d.cpp
//========================================
#include "spell_d.hpp"

//----------------------------------------
// DATA - SPELL
//----------------------------------------
using namespace opal;

//----------------------------------------
// constructor & destructor
//----------------------------------------
namespace {
	extern const std::unordered_map<SPELL_KIND,std::string>	spell_name;
}

namespace DATA_SPELL {
	auto SpellName( SPELL_KIND k )->std::string{ return "";	}

	auto SpellKind( const std::string& s )->SPELL_KIND{

		return SPELL_KIND::Undef;
	}

	auto SpellKind( void )->SPELL_KIND{ return SPELL_KIND::Undef;	}
}

namespace {
	DECLTYPE( spell_name ) = {
			{ SPELL_KIND::FireBall,			"FireBall"				},
	};
}

// End Of File
