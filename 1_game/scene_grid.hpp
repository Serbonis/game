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

private:
	opal::SSIZE2U	size;
	opal::SSIZE2U	offset;

public:
	void Init( const char* = nullptr ) override;
	void Free( void ) override;

private:
	void ObjFunc( void ) override;

public:
	void Generate( UINT, UINT, UINT, UINT );
	void Destroy( void );

public:
	auto Size(   void ) const->opal::SSIZE2U;
	auto Offset( void ) const->opal::SSIZE2U;

public:
	void ObjPosition( int, int );

private:
	auto Grid( UINT, UINT ) const->std::shared_ptr<class GRID_M>;

public:
	void SetFloor( UINT, UINT, GRID_KIND_FLOOR = GRID_KIND_FLOOR::Undef );
	void SetCeil(  UINT, UINT, GRID_KIND_CEIL = GRID_KIND_CEIL::Undef );
	void SetWall(  UINT, UINT, opal::DIX, GRID_KIND_WALL = GRID_KIND_WALL::Undef );

	auto GetFloor( UINT, UINT ) const->GRID_KIND_FLOOR;
	auto GetCeil(  UINT, UINT ) const->GRID_KIND_CEIL;
	auto GetWall(  UINT, UINT, opal::DIX ) const->GRID_KIND_WALL;
};

// End Of File
