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
	bool PlayerDebug( void ){ return PADX::KeyPush( KEY_I );	}

	bool PlayerMoveF(    void ){ return PADX::KeyPush( KEY_W );		}
	bool PlayerMoveB(    void ){ return PADX::KeyPush( KEY_S );		}
	bool PlayerMoveL(    void ){ return PADX::KeyPush( KEY_A );		}
	bool PlayerMoveR(    void ){ return PADX::KeyPush( KEY_D );		}
	bool PlayerTurnL(    void ){ return PADX::KeyTrig( KEY_Q );		}
	bool PlayerTurnR(    void ){ return PADX::KeyTrig( KEY_E );		}
	bool PlayerJump(     void ){ return PADX::KeyPush( KEY_SPACE );	}

	bool PlayerFireBall( void ){ return PADX::KeyTrig( KEY_B );		}
}

// End Of File
