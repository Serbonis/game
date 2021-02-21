#pragma once
//========================================
// scene_camera.hpp
//========================================
#include "workx.hpp"

//----------------------------------------
// SCENE CAMERA
//----------------------------------------
class SCENE_CAMERA final : public opal::WORKL{
public:
	void Init( const char* = nullptr ) override;
	void Free( void ) override;

private:
	void ObjFunc( void ) override;

private:
	std::shared_ptr<class PLATFORM>	platform;
	std::shared_ptr<class CAMERA_X>	camera;
	std::shared_ptr<class CAMERA_X>	handy;
	UINT	number;

public:
	void SetConnect( const class ACTOR_X* );

public:
	void SetCamera( UINT );
	void SetCamera( void );
	auto GetCamera( void ) const->UINT;

public:
	void SetPosition( int, int );
	void SetDirection( int );
};

// End Of File
