#pragma once
//========================================
// radar_v.hpp
//========================================
#include "rect2.hpp"
#include "waku2.hpp"
#include "texture.hpp"
#include "mapper.hpp"
#include "mapper_v.hpp"

#include "layout.hpp"

//----------------------------------------
// RADAR - VIEW
//----------------------------------------
class RADAR_VIEW final :
	public opal::DRAWL,
	public MAPPER_VIEW_I
{
private:
	float	grid_size;

public:
	static constexpr UINT	FRAME_RADAR_ORDER = 10;

private:
	TEXTURE	texture_arrow;
	TEXTURE	texture_dir[opal::DIX_MAX];

private:
	WAKU2	waku;
	MAPPER	mapper{FRAME_RADAR_ORDER};
	RECT2	arrow;
	DRAWL	dix;
	RECT2	dir[opal::DIX_MAX];

public:
	void Init( const char* = nullptr ) override;
	void Free( void ) override;

public:
	void Clear( void ) override;

public:
	void Floor(  UINT, UINT,            opal::COLOR = opal::BLANK ) override;
	void Wall(   UINT, UINT, opal::DIX, opal::COLOR = opal::BLANK ) override;
	void Corner( UINT, UINT, UINT,      opal::COLOR = opal::BLANK ) override;

public:
	void Move( UINT, UINT );
	void Turn( float );

public:
	void WakuColor(  UINT );
	void ArrowColor( UINT );
};

// End Of File
