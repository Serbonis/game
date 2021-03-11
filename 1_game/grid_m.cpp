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
// èâä˙âª
//----------------------------------------
void GRID_M::Init( const char* p ){

	WORKT::Init( p );

	view = nullptr;

	c = GRID_KIND_CEIL::Undef;
	f = GRID_KIND_FLOOR::Undef;
	for ( auto i = 0UL; i < DIX_MAX; i++ ) {
		w[i] = GRID_KIND_WALL::Undef;
	}
}

//----------------------------------------
// å„énññ
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

void GRID_M::SetFloor( GRID_KIND_FLOOR k       ){ view->SetFloor( f = k );		}
void GRID_M::SetCeil(  GRID_KIND_CEIL k        ){ view->SetCeil(  c = k );		}
void GRID_M::SetWall(  DIX d, GRID_KIND_WALL k ){ view->SetWall( d, w[d] = k );	}

auto GRID_M::GetFloor( void  ) const->GRID_KIND_FLOOR{ return f;	}
auto GRID_M::GetCeil(  void  ) const->GRID_KIND_CEIL{  return c;	}
auto GRID_M::GetWall(  DIX d ) const->GRID_KIND_WALL{  return ( d != DIX_MAX ) ? w[d] : GRID_KIND_WALL::Undef;	}

// End Of File
