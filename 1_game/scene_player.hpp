#pragma once
//========================================
// scene_player.hpp
//========================================
#include "workx.hpp"

//----------------------------------------
// SCENE PLAYER
//----------------------------------------
class SCENE_PLAYER final : public opal::WORKL{
public:
	void Init( const char* = nullptr ) override;
	void Free( void ) override;

private:
	void ObjFunc( void ) override;

private:
	std::shared_ptr<class PLAYER_X>	player;

public:
	auto GetConnect( void ) const->const class ACTOR_X*;

public:
	void SetPosition( int, int );
	void SetDirection( int );
};

// End Of File
