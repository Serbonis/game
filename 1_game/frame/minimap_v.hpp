#pragma once
//========================================
// minimap_v.hpp
//========================================
#include "rect2.hpp"
#include "waku2.hpp"
#include "font.hpp"
//#include "shape.hpp"
//#include "polygon.hpp"
#include "texture.hpp"
#include "mapper.hpp"
#include "mapper_v.hpp"

#include "layout.hpp"

//----------------------------------------
// MINIMAP - VIEW
//----------------------------------------
class MINIMAP_VIEW final :
	public opal::DRAWL,
	public MAPPER_VIEW_I
{
private:
	float	grid_size;

public:
	static constexpr UINT	FRAME_MINIMAP_ORDER	= 10;

private:
	TEXTURE	texture_arrow;
	//POLYGON	polygon_radar;

private:
	WAKU2	waku;
	MAPPER	mapper{FRAME_MINIMAP_ORDER};
	FONT	name;
	RECT2	arrow;
	//SHAPE	radar;

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
	void Move( float, float );

public:
	void MapName( const std::string& = "" );

public:
	void WakuColor(  UINT );
};

// End Of File
