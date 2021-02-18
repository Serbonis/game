//========================================
// grid_m.cpp
//========================================
#include "grid_m.hpp"
#include "grid_v.hpp"

//----------------------------------------
// GRID M
//----------------------------------------
using namespace opal;

//----------------------------------------
// ‰Šú‰»
//----------------------------------------
void GRID_M::Init( const char* p ){

	WORKT::Init( p );

	view = nullptr;
}

//----------------------------------------
// ŒãŽn––
//----------------------------------------
void GRID_M::Free( void ){

	view = nullptr;

	WORKT::Free();
}

//----------------------------------------
//----------------------------------------
void GRID_M::SetView( void ){

	view = nullptr;
}

void GRID_M::SetView( DRAWL* d ){

	makeshared2( view, []( GRID_V* v ){ v->Close(); } );

	view->Open( d );
	view->Parent( this );
}

//----------------------------------------
//----------------------------------------
float GRID_M::operator =( float s ){

	*view = s;

	return s;
}

void GRID_M::SetFloor( GRID_KIND_FLOOR k       ){ view->SetFloor( k );		}
void GRID_M::SetCeil(  GRID_KIND_CEIL k        ){ view->SetCeil(  k );		}
void GRID_M::SetWall(  DIX d, GRID_KIND_WALL k ){ view->SetWall( d, k );	}

// End Of File
