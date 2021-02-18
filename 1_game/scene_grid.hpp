#pragma once
//========================================
// scene_grid.hpp
//========================================
#include "workx.hpp"
#include "drawx.hpp"
#include "grid_k.hpp"

//----------------------------------------
// SCENE GRID
//----------------------------------------
class SCENE_GRID final : public opal::WORKL{
private:
	opal::DRAWL	draw;
	std::shared_ptr<std::vector<std::vector<std::shared_ptr<class GRID_M>>>>	grid;
	opal::SSIZE2U	size;

public:
	void Init( const char* = nullptr ) override;
	void Free( void ) override;

private:
	void ObjFunc( void ) override;

public:
	void Generate( opal::SSIZE2U = {} );
	void Generate( UINT, UINT );
	void Destroy( void );

public:
	void SetPosition( int, int );

public:
	void SetFloor( UINT, UINT, GRID_KIND_FLOOR = GRID_KIND_FLOOR::Undef );
	void SetCeil(  UINT, UINT, GRID_KIND_CEIL = GRID_KIND_CEIL::Undef );
	void SetWall(  UINT, UINT, opal::DIX, GRID_KIND_WALL = GRID_KIND_WALL::Undef );
};

// End Of File
