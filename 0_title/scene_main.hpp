#pragma once
//========================================
// scene_main.hpp
//========================================
#include "game.hpp"

//----------------------------------------
// SCENE MAIN
//----------------------------------------
namespace SCENE_TITLE {
	class SCENE_M final : public SCENE<class SCENE_G> {
	public:
		explicit SCENE_M();
		virtual ~SCENE_M();

	private:
		auto SceneMain( SCENE_MANAGER* )->SCENE_NAME override;
	};
}

// End Of File
