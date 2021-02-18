//========================================
// scene_main.cpp
//========================================
#include "scene_main.hpp"
#include "scene_game.hpp"

//----------------------------------------
// SCENE MAIN
//----------------------------------------
using namespace opal;

//----------------------------------------
// constructor & destructor
//----------------------------------------
namespace SCENE_TITLE {
	SCENE_M::SCENE_M(){}
	SCENE_M::~SCENE_M(){}
}

//----------------------------------------
// XV
//----------------------------------------
namespace SCENE_TITLE {
	auto SCENE_M::SceneMain( SCENE_MANAGER* scene )->SCENE_NAME{ return (*impl)( scene ) ? "GAME" : "";	}
}

// End Of File
