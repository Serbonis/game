//========================================
// mapper.cpp
//========================================
#include "mapper.hpp"

//----------------------------------------
// MAPPER
//----------------------------------------
using namespace opal;

//----------------------------------------
//----------------------------------------
MAPPER::MAPPER( UINT n )
{
	canvas.Init( std::pow( 2, ( 0 < n && n <= 10 ) ? n : 10 ) );
}
MAPPER::~MAPPER()
{
	canvas.Free();
}

//----------------------------------------
//----------------------------------------
void MAPPER::Init( const char* p ){

	RECT2::Init( p );
	RECT2::SetTexture( canvas );
}

void MAPPER::Free( void ){

	RECT2::Free();
}

//---------------------------------------
//---------------------------------------
void MAPPER::Canvas( const VECTOR2& p, const SSIZE& s ){ position = p; size = s;	}
void MAPPER::Canvas( const VECTOR2& p ){ position = p;	}
void MAPPER::Canvas( const SSIZE&   s ){ size = s;		}

//---------------------------------------
//---------------------------------------
void MAPPER::Mapping( UINT x, UINT y, UINT w, UINT h, COLOR c ){

	if ( SURFACE_LOCK lock{canvas} ) {
		lock.SetPixel( x, y, w, h, c );
	}
}

//----------------------------------------
//----------------------------------------
void MAPPER::DrawMain( void ){

	DRAWX::SetScissor( position, size );
	RECT2::DrawMain();
	DRAWX::SetScissor();
}

// End Of File
