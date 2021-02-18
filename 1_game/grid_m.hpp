#pragma once
//========================================
// grid_m.hpp
//========================================
#include "workx.hpp"
#include "grid_k.hpp"

//----------------------------------------
// GRID M
//----------------------------------------
namespace opal {
	class DRAWL;
}

class GRID_M final : public opal::WORKT{
protected:
	std::shared_ptr<class GRID_V>	view;

public:
	void Init( const char* = nullptr ) override;
	void Free( void ) override;

public:
	void SetView( void );
	void SetView( opal::DRAWL* = nullptr );

public:
	virtual float operator =( float );

public:
	void SetFloor( GRID_KIND_FLOOR = GRID_KIND_FLOOR::Undef );
	void SetCeil(  GRID_KIND_CEIL = GRID_KIND_CEIL::Undef );
	void SetWall(  opal::DIX, GRID_KIND_WALL = GRID_KIND_WALL::Undef );
};

// End Of File
