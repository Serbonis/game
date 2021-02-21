#pragma once
//========================================
// camera_x.hpp
//========================================
#include "actor_x.hpp"
#include "camera.hpp"

//----------------------------------------
// CAMERA X
//----------------------------------------
class CAMERA_C :
	public ACTOR_C<ACTOR_A_MOVE,ACTOR_A_ROTATE>
{};

class CAMERA_X :
	public ACTOR_X,
	public CAMERA_C
{
protected:
	opal::DRAWL		view;
	opal::DRAWT		armv;
	opal::DRAWT		armh;
	CAMERA			camera;

public:
	virtual void Init( const char* = nullptr ) override;
	virtual void Free( void ) override;

public:
	virtual auto operator ()( void ) const->const opal::CAMERAX* final;

public:
	virtual void SetArmV( float ) final;
	virtual void SetArmH( float ) final;
	virtual void AddArmV( float ) final;
	virtual void AddArmH( float ) final;
	virtual auto GetArmV( void ) const->float final;
	virtual auto GetArmH( void ) const->float final;

public:
	virtual void SetTilt( float ) final;
	virtual void SetPan(  float ) final;
	virtual void SetZoom( float ) final;
	virtual void AddTilt( float ) final;
	virtual void AddPan(  float ) final;
	virtual void AddZoom( float ) final;
	virtual auto GetTilt( void ) const->float final;
	virtual auto GetPan(  void ) const->float final;
	virtual auto GetZoom( void ) const->float final;

#if OPAL_DEBUG
public:
	virtual void Debug( float = 0.04f,
						float = RAD( 4.0f ),
						float = 0.01f ) final;
#endif
};

// End Of File
