//========================================
// player_d.cpp
//========================================
#include "player_d.hpp"

//----------------------------------------
// DATA - PLAYER
//----------------------------------------
using namespace opal;

//----------------------------------------
// constructor & destructor
//----------------------------------------
namespace {
	extern const std::unordered_map<PLAYER_KIND,std::string>	player_name;
}

namespace DATA_PLAYER {
	auto PlayerName( PLAYER_KIND k )->std::string{ return "";	}

	auto PlayerKind( const std::string& s )->PLAYER_KIND{

		return PLAYER_KIND::Undef;
	}

	auto PlayerKind( void )->PLAYER_KIND{ return PLAYER_KIND::Undef;	}
}

namespace {
	DECLTYPE( player_name ) = {
	  { PLAYER_KIND::Alex,		"Alex Ander"				},
	  { PLAYER_KIND::Azizi,		"Azizi Johari"				},
	  { PLAYER_KIND::Boris,		"Boris Wizard Of Baldor"	},
	  { PLAYER_KIND::Chani,		"Chani Sayyadina Sihaya"	},
	  { PLAYER_KIND::Daroou,	"Daroou"					},
	  { PLAYER_KIND::Elija,		"Elija Lion Of Yaitopya"	},
	  { PLAYER_KIND::Gando,		"Gando Thurfoot"			},
	  { PLAYER_KIND::Gothmog,	"Gothmog"					},
	  { PLAYER_KIND::Halk,		"Halk The Barbarian"		},
	  { PLAYER_KIND::Hawk,		"Hawk The Fearless"			},
	  { PLAYER_KIND::Hissssa,	"Hissssa Lizar Of Makan"	},
	  { PLAYER_KIND::Iaido,		"Iaido Ruyito Chiburi"		},
	  { PLAYER_KIND::Leif,		"Leif The Valiant"			},
	  { PLAYER_KIND::Leyla,		"Leyla Shadowseek"			},
	  { PLAYER_KIND::Linflas,	"Linflas"					},
	  { PLAYER_KIND::Mophus,	"Mophus The Healer"			},
	  { PLAYER_KIND::Nabi,		"Nabi The Prophet"			},
	  { PLAYER_KIND::Sonja,		"Sonja She Devil"			},
	  { PLAYER_KIND::Stamm,		"Stamm Bladecaster"			},
	  { PLAYER_KIND::Syra,		"Syra Child Of Nature"		},
	  { PLAYER_KIND::Tiggy,		"Tiggy Tamal"				},
	  { PLAYER_KIND::Wu,		"Wu Tse Son Of Heaven"		},
	  { PLAYER_KIND::Wuuf,		"Wuuf The Bika"				},
	  { PLAYER_KIND::Zed,		"Zed Duke Of Banville"		},
	};
}

// End Of File
