#pragma once
//========================================
// scene_camera.hpp
//========================================
#include "workx.hpp"

//----------------------------------------
// SCENE CAMERA
//----------------------------------------
class ACTOR_X;
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
	void SetConnect( std::weak_ptr<const ACTOR_X> );
	auto GetConnect( void ) const->std::weak_ptr<const ACTOR_X>;

public:
	void SetCamera( UINT );
	void SetCamera( void );
	auto GetCamera( void ) const->UINT;

public:
	void ObjPosition( int, int );
	void ObjDirection( int );
};

// End Of File
