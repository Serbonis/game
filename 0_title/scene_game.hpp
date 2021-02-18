#pragma once
//========================================
// scene_game.hpp
//========================================
#include "scene_main.hpp"

//----------------------------------------
// SCENE GAME
//----------------------------------------
#include "font.hpp"

namespace SCENE_TITLE {
	class SCENE_G final {
	private:
		FONT	title;

	public:
		SCENE_G();
		~SCENE_G();

	public:
		bool operator()( class SCENE_MANAGER* );
	};
}

// End Of File
