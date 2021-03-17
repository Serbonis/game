#pragma once
//========================================
// grid_k.hpp
//========================================
#include "com.hpp"

//----------------------------------------
// GRID KIND
//----------------------------------------
enum class GRID_KIND_FLOOR {
	  Undef,
	  Normal,
	  Portal,
	  Block,
};

enum class GRID_KIND_CEIL {
	  Undef,
	  Normal,
};

enum class GRID_KIND_WALL {
	  Undef,
	  Normal,
};

extern bool GRID_KIND_FLOOR_Exist( GRID_KIND_FLOOR );

extern bool GRID_KIND_WALL_Exist( GRID_KIND_WALL );
extern UINT GRID_KIND_WALL_Exist( const GRID_KIND_WALL[] );

// End Of File
