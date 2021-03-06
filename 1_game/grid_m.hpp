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

protected:
	GRID_KIND_CEIL	c;
	GRID_KIND_FLOOR	f;
	GRID_KIND_WALL	w[opal::DIX_MAX];
	UINT			x;

protected:
	struct DISPLAY {
		bool operator()( void );
		bool	eliminate{false};
	} display;

public:
	void Init( const char* = nullptr ) override;
	void Free( void ) override;

private:
	void ObjFunc( void ) override;

public:
	void SetView( void );
	void SetView( opal::DRAWL* = nullptr );

public:
	float operator =( float );

public:
	void SetFloor( GRID_KIND_FLOOR = GRID_KIND_FLOOR::Undef );
	void SetCeil(  GRID_KIND_CEIL = GRID_KIND_CEIL::Undef );
	void SetWall(  opal::DIX, GRID_KIND_WALL = GRID_KIND_WALL::Undef );
	void SetCorner( void );

	auto GetFloor( void ) const->GRID_KIND_FLOOR;
	auto GetCeil(  void ) const->GRID_KIND_CEIL;
	auto GetWall(  opal::DIX ) const->GRID_KIND_WALL;
	auto GetCorner( void ) const->UINT;

public:
	void SetEliminate( int = opal::FLAG_FLIP );
	bool GetEliminate( void ) const;
};

// End Of File
