#pragma once
//========================================
// grid_d.hpp
//========================================
#include "com.hpp"
#include "grid_k.hpp"

//----------------------------------------
// DATA - GRID
//----------------------------------------
namespace DATA_GRID {
	extern auto GridKindFloor( const std::string& )->GRID_KIND_FLOOR;
	extern auto GridKindCeil(  const std::string& )->GRID_KIND_CEIL;
	extern auto GridKindWall(  const std::string& )->GRID_KIND_WALL;

	extern auto GridKindFloor( void )->GRID_KIND_FLOOR;
	extern auto GridKindCeil(  void )->GRID_KIND_CEIL;
	extern auto GridKindWall(  void )->GRID_KIND_WALL;
}

// End Of File
