//========================================
// enemy_d.cpp
//========================================
#include "enemy_d.hpp"

//----------------------------------------
// DATA - ENEMY
//----------------------------------------
using namespace opal;

//----------------------------------------
// constructor & destructor
//----------------------------------------
namespace {
	extern const std::unordered_map<ENEMY_KIND,std::string>	enemy_name;
}

namespace DATA_ENEMY {
	auto EnemyName( ENEMY_KIND k )->std::string{ return "";	}

	auto EnemyKind( const std::string& s )->ENEMY_KIND{

		return ENEMY_KIND::Undef;
	}

	auto EnemyKind( void )->ENEMY_KIND{ return ENEMY_KIND::Undef;	}
}

namespace {
	DECLTYPE( enemy_name ) = {
			{ ENEMY_KIND::Mummy,			"Mummy"				},
			{ ENEMY_KIND::Screamer,			"Screamer"			},
			{ ENEMY_KIND::Giggler,			"Giggler"			},
			{ ENEMY_KIND::Rock_Pile,		"Rock Pile"			},
			{ ENEMY_KIND::Slime,			"Slime"				},
			{ ENEMY_KIND::Wing_Eye,			"Wing Eye"			},
			{ ENEMY_KIND::Ghost,			"Ghost"				},
			{ ENEMY_KIND::Muncher,			"Muncher"			},
			{ ENEMY_KIND::Skeleton,			"Skeleton"			},
			{ ENEMY_KIND::Worm,				"Worm"				},
			{ ENEMY_KIND::Fire_Elemental,	"Fire Elemental"	},
			{ ENEMY_KIND::Water_Elemental,	"Water Elemental"	},
			{ ENEMY_KIND::Goblin,			"Goblin"			},
			{ ENEMY_KIND::Giant_Rat,		"Giant Rat"			},
			{ ENEMY_KIND::Ant_Man,			"Ant Man"			},
			{ ENEMY_KIND::Beholder,			"Beholder"			},
			{ ENEMY_KIND::Couatyl,			"Couatyl"			},
			{ ENEMY_KIND::Fader,			"Fader"				},
			{ ENEMY_KIND::Tentacle_Beast,	"Tentacle Beast"	},
			{ ENEMY_KIND::Scorpion,			"Scorpion"			},
			{ ENEMY_KIND::Demon,			"Demon"				},
			{ ENEMY_KIND::Deth_Knight,		"Deth Knight"		},
			{ ENEMY_KIND::Spider,			"Spider"			},
			{ ENEMY_KIND::Stone_Golem,		"Stone Golem"		},
			{ ENEMY_KIND::Sorcerer,			"Sorcerer"			},
			{ ENEMY_KIND::Dragon,			"Dragon"			},
			{ ENEMY_KIND::Lord_Chaos,		"Lord Chaos"		},
			{ ENEMY_KIND::Demon_Lord,		"Demon Lord"		},
			{ ENEMY_KIND::Vexirk,			"Vexirk"			},
			{ ENEMY_KIND::Hell_Hound,		"Hell Hound"		},
			{ ENEMY_KIND::Giant_Wasp,		"Giant Wasp"		},
			{ ENEMY_KIND::Blue_Ogre,		"Blue Ogre"			},
	};
}

// End Of File
