//========================================
// controll.cpp
//========================================
#include "controll.hpp"
#include "pad.hpp"

//----------------------------------------
// CONTROLL
//----------------------------------------
using namespace opal;

//----------------------------------------
// com
//----------------------------------------
namespace CONTROLL {
	bool DebugScene( void ){ return PADX::KeyTrig( KEY_P );	}
}

//----------------------------------------
// game
//----------------------------------------
namespace CONTROLL {
	bool GameDebug(  void ){ return PADX::KeyTrig( KEY_L );	}
	bool FrameDebug( void ){ return PADX::KeyTrig( KEY_U );	}
	bool RestartMap( void ){ return PADX::KeyTrig( KEY_M );	}
	bool AtariDebug( void ){ return PADX::KeyTrig( KEY_O );	}
}

namespace CONTROLL {
	bool CameraDebug(  void ){ return PADX::KeyPush( KEY_LSHIFT );	}
	bool CameraChange( void ){ return PADX::KeyTrig( KEY_RSHIFT );	}

	bool CameraAddArmH( void ){ return PADX::KeyPush( KEY_R );	}
	bool CameraAddArmV( void ){ return PADX::KeyPush( KEY_T );	}
	bool CameraAddTilt( void ){ return PADX::KeyPush( KEY_Y );	}
	bool CameraAddPan(  void ){ return PADX::KeyPush( KEY_U );	}
	bool CameraAddZoom( void ){ return PADX::KeyPush( KEY_J );	}
}

namespace CONTROLL {
	static inline UINT keycode( const std::string& s, UINT n ){
		static const std::unordered_map<std::string,std::vector<UINT>>	keymap
			= {
			   { "Debug",		{ KEY_I } },
			   { "MoveF",		{ KEY_W } },
			   { "MoveB",		{ KEY_S } },
			   { "MoveL",		{ KEY_A } },
			   { "MoveR",		{ KEY_D } },
			   { "TurnL",		{ KEY_Q } },
			   { "TurnR",		{ KEY_E } },
			   { "Jump",		{ KEY_SPACE } },
			   { "FireBall",	{ KEY_B } },
		};

		if ( mapfind( keymap, s ) ) {
			if ( const auto m = mapped( keymap, s ); n < m.size() ) {
				return m.at( n );
			}
		}

		return KEY_NULL;
	}

	bool PlayerDebug( UINT n ){ return PADX::KeyPush( keycode( "Debug", n ) );			}

	bool PlayerMoveF(    UINT n ){ return PADX::KeyPush( keycode( "MoveF", n ) );		}
	bool PlayerMoveB(    UINT n ){ return PADX::KeyPush( keycode( "MoveB", n ) );		}
	bool PlayerMoveL(    UINT n ){ return PADX::KeyPush( keycode( "MoveL", n ) );		}
	bool PlayerMoveR(    UINT n ){ return PADX::KeyPush( keycode( "MoveR", n ) );		}
	bool PlayerTurnL(    UINT n ){ return PADX::KeyTrig( keycode( "TurnL", n ) );		}
	bool PlayerTurnR(    UINT n ){ return PADX::KeyTrig( keycode( "TurnR", n ) );		}
	bool PlayerJump(     UINT n ){ return PADX::KeyPush( keycode( "Jump", n ) );		}
	bool PlayerFireBall( UINT n ){ return PADX::KeyTrig( keycode( "FireBall", n ) );	}
}

// End Of File
