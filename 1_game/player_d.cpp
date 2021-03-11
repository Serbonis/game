//========================================
// player_d.cpp
//========================================
#include "player_d.hpp"

//----------------------------------------
// DATA - PLAYER
//----------------------------------------
using namespace opal;

//----------------------------------------
//----------------------------------------
namespace DATA_PLAYER {
	const float	PLAYER_MOVE_SPEED	= 0.16F;
	const float	PLAYER_TURN_SPEED	= RAD( 8.0f );
	const float	PLAYER_JUMP_SPEED	= 0.16F;
	const float	PLAYER_SPELL_SPEED	= 0.4f;
	const float	PLAYER_SPELL_POWER	= 0;
	const float	PLAYER_SPELL_PIVOT	= 2;
}

//----------------------------------------
//----------------------------------------
namespace {
	extern const std::unordered_map<PLAYER_KIND,std::string>	player_name;
	extern const std::unordered_map<PLAYER_KIND,PLAYER_PARAM>	player_param;
	extern const PLAYER_PARAM	default_player_param;
}

namespace DATA_PLAYER {
	auto PlayerName( PLAYER_KIND k )->std::string{

		return mapfind( player_name, k ) ? mapat( player_name, k ) : "";
	}

	auto PlayerParam( PLAYER_KIND k )->PLAYER_PARAM{

		return mapfind( player_param, k ) ? mapat( player_param, k ) : default_player_param;
	}
}

//----------------------------------------
//----------------------------------------
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

namespace {
	DECLTYPE( default_player_param ) =
		{
		 PARAMETER::VALMAX{ 100, 100 },	// HP
		 PARAMETER::VALMAX{ 100, 100 },	// MP
		 PARAMETER::MOVE{ DATA_PLAYER::PLAYER_MOVE_SPEED },
		 PARAMETER::TURN{ DATA_PLAYER::PLAYER_TURN_SPEED },
		 PARAMETER::JUMP{ DATA_PLAYER::PLAYER_JUMP_SPEED },
		};

	DECLTYPE( player_param ) = {
	  { PLAYER_KIND::Alex,		{} },
	  { PLAYER_KIND::Azizi,		{} },
	  { PLAYER_KIND::Boris,		{} },
	  { PLAYER_KIND::Chani,		{} },
	  { PLAYER_KIND::Daroou,	{} },
	  { PLAYER_KIND::Elija,		{} },
	  { PLAYER_KIND::Gando,		{} },
	  { PLAYER_KIND::Gothmog,	{} },
	  { PLAYER_KIND::Halk,		{} },
	  { PLAYER_KIND::Hawk,		{} },
	  { PLAYER_KIND::Hissssa,	{} },
	  { PLAYER_KIND::Iaido,		{} },
	  { PLAYER_KIND::Leif,		{} },
	  { PLAYER_KIND::Leyla,		{} },
	  { PLAYER_KIND::Linflas,	{} },
	  { PLAYER_KIND::Mophus,	{} },
	  { PLAYER_KIND::Nabi,		{} },
	  { PLAYER_KIND::Sonja,		{} },
	  { PLAYER_KIND::Stamm,		{} },
	  { PLAYER_KIND::Syra,		{} },
	  { PLAYER_KIND::Tiggy,		{} },
	  { PLAYER_KIND::Wu,		{} },
	  { PLAYER_KIND::Wuuf,		{} },
	  { PLAYER_KIND::Zed,		{} },
	};
}
// End Of File
