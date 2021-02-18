#pragma once
//========================================
// game.hpp
//========================================
#include "opal.hpp"
#include "scene.hpp"

//----------------------------------------
// GAME
//----------------------------------------
class GAME final : public OPAL::FUNC{
public:
	static inline const std::string PROJECT = "SAMPLE";

private:
	void SysInit( void ) override;
	void SysExec( void ) override;
	void SysFree( void ) override;

private:
	std::shared_ptr<SCENE_MANAGER>	scene;

public:
	auto SceneManager( void ) const->auto{ return scene;	}
};

// End Of File
