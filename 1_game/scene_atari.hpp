#pragma once
//========================================
// scene_atari.hpp
//========================================
#include "workx.hpp"
#include "atari.hpp"

//----------------------------------------
// SCENE ATARI
//----------------------------------------
class ACTOR_X;
class SCENE_ATARI final : public opal::WORKL {
public:
	static inline const std::string	PLAYER = "PLAYER";
	static inline const std::string	ENEMY  = "ENEMY";
	static inline const std::string	P_SHOT = "P_SHOT";
	static inline const std::string	E_SHOT = "E_SHOT";

public:
	void Init( const char* = nullptr ) override;
	void Free( void ) override;

private:
	void ObjFunc( void ) override;

private:
	std::shared_ptr<ATARIS>	server;

public:
	void AtariRegister( const char*, std::shared_ptr<ACTOR_X> );
	void AtariRelease(  const char*, std::shared_ptr<ACTOR_X> );
};

// End Of File
