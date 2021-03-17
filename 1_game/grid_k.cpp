//========================================
// grid_k.cpp
//========================================
#include "grid_k.hpp"

//----------------------------------------
// GRID KIND
//----------------------------------------
using namespace opal;

//----------------------------------------
//----------------------------------------
bool GRID_KIND_FLOOR_Exist( GRID_KIND_FLOOR k ){

	switch ( k ) {
	case GRID_KIND_FLOOR::Normal:	return true;
	case GRID_KIND_FLOOR::Portal:	return true;
	case GRID_KIND_FLOOR::Block:	return true;
	default: break;
	}
	return false;
}

bool GRID_KIND_WALL_Exist( GRID_KIND_WALL k ){

	switch ( k ) {
	case GRID_KIND_WALL::Normal:	return true;
	default: break;
	}
	return false;
}

UINT GRID_KIND_WALL_Exist( const GRID_KIND_WALL w[] ){

	UINT	x = DIC_X;

	if ( GRID_KIND_WALL_Exist( w[DIX_N] ) ) { x |= DIC_I|DIC_U;	}
	if ( GRID_KIND_WALL_Exist( w[DIX_E] ) ) { x |= DIC_U|DIC_T;	}
	if ( GRID_KIND_WALL_Exist( w[DIX_S] ) ) { x |= DIC_T|DIC_H;	}
	if ( GRID_KIND_WALL_Exist( w[DIX_W] ) ) { x |= DIC_H|DIC_I;	}

	return x;
}

// End Of File
