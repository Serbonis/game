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
	extern bool FrameDebug( void );
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
	extern bool PlayerDebug( UINT );

	extern bool PlayerMoveF(    UINT );
	extern bool PlayerMoveB(    UINT );
	extern bool PlayerMoveL(    UINT );
	extern bool PlayerMoveR(    UINT );
	extern bool PlayerTurnL(    UINT );
	extern bool PlayerTurnR(    UINT );
	extern bool PlayerJump(     UINT );

	extern bool PlayerFireBall( UINT );
}

// End Of File
