#pragma once
//========================================
// controll.hpp
//========================================
#include "opal.hpp"

//----------------------------------------
// CONTROLL
//----------------------------------------
//----------------------------------------
// com
//----------------------------------------
namespace CONTROLL {
	extern bool DebugScene( void );
}

//----------------------------------------
// game
//----------------------------------------
namespace CONTROLL {
	extern bool GameDebug(  void );
	extern bool RestartMap( void );
	extern bool AtariDebug( void );
}

namespace CONTROLL {
	extern bool CameraDebug(  void );
	extern bool CameraChange( void );

	extern bool CameraAddArmH( void );
	extern bool CameraAddArmV( void );
	extern bool CameraAddTilt( void );
	extern bool CameraAddPan(  void );
	extern bool CameraAddZoom( void );
}

namespace CONTROLL {
	extern bool PlayerDebug( void );

	extern bool PlayerMoveF(    void );
	extern bool PlayerMoveB(    void );
	extern bool PlayerMoveL(    void );
	extern bool PlayerMoveR(    void );
	extern bool PlayerTurnL(    void );
	extern bool PlayerTurnR(    void );
	extern bool PlayerJump(     void );

	extern bool PlayerFireBall( void );
}

// End Of File
