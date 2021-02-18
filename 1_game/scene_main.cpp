//========================================
// scene_main.cpp
//========================================
#include "scene_main.hpp"
#include "scene_game.hpp"

//----------------------------------------
// SCENE GAME
//----------------------------------------
using namespace opal;

//----------------------------------------
// constructor & destructor
//----------------------------------------
namespace SCENE_GAME {
	SCENE_M::SCENE_M(){}
	SCENE_M::~SCENE_M(){}
}

//----------------------------------------
// XV
//----------------------------------------
namespace SCENE_GAME {
	auto SCENE_M::SceneMain( SCENE_MANAGER* scene )->SCENE_NAME{ return (*impl)( scene ) ? "" : "";	}
}

// End Of File
