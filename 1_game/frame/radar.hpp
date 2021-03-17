#pragma once
//========================================
// radar.hpp
//========================================
#include "drawx.hpp"
#include "mapper_v.hpp"

//----------------------------------------
// FRAME - RADAR
//----------------------------------------
class FRAME_RADAR final :
	public opal::DRAWL,
	public MAPPER_VIEW<class RADAR_VIEW>
{
	using MAPPER_VIEW::size;

public:
	void Init( const char* = nullptr ) override;
	void Free( void ) override;

public:
	void Clear( void );

public:
	void Move( UINT, UINT );
	void Turn( float );

private:
	void ObjFunc( void ) override;

#if OPAL_DEBUG
public:
	void Debug( void ) const;
#endif
};

// End Of File

