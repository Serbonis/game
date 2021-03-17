#pragma once
//========================================
// map.hpp
//========================================
#include "com.hpp"

//----------------------------------------
// MAP DATA
//----------------------------------------
struct MAP_DATA {
	// MAP
	const std::string	name;

	struct {
		const std::string*		data;
		std::pair<UINT,UINT>	size;
		std::pair<int,int>		offset;
	}	map;

	// PLAYER
	struct {
		const struct PLAYER_DATA*	data;
		UINT						number;
	}	player;

	// ENEMY
	struct {
		const struct ENEMY_DATA*	data;
		UINT						number;
	}	enemy;

	auto GridData( UINT, UINT ) const->std::shared_ptr<struct GRID_DATA>;

	auto GridDataFloor( UINT, UINT ) const->std::string;
	auto GridDataCeil(  UINT, UINT ) const->std::string;
	auto GridDataWall(  UINT, UINT, opal::DIX ) const->std::string;
};

//----------------------------------------
// GRID DATA
//----------------------------------------
#include "grid_k.hpp"

struct GRID_DATA {
	GRID_DATA();
	GRID_DATA( GRID_KIND_FLOOR, GRID_KIND_CEIL, GRID_KIND_WALL, GRID_KIND_WALL, GRID_KIND_WALL, GRID_KIND_WALL );
	GRID_DATA( GRID_KIND_FLOOR, GRID_KIND_CEIL, const std::vector<GRID_KIND_WALL>& );

	GRID_KIND_FLOOR		f;
	GRID_KIND_CEIL		c;
	GRID_KIND_WALL		w[opal::DIX_MAX];
};

//----------------------------------------
// PLAYER DATA
//----------------------------------------
struct PLAYER_DATA {
	std::pair<UINT,UINT>	position;
	opal::DIM				offset;
	UINT					direction;
};

//----------------------------------------
// ENEMY DATA
//----------------------------------------
#include "enemy_k.hpp"
#include "enemy_s.hpp"

struct ENEMY_DATA {
	ENEMY_KIND				kind;
	std::pair<UINT,UINT>	position;
	opal::DIM				offset;
	UINT					direction;
	UINT					stat;
};

//----------------------------------------
// ITEM DATA
//----------------------------------------
struct ITEM_DATA {
};

// End Of File
