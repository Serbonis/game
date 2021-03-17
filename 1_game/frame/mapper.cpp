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

//----------------------------------------
//----------------------------------------
auto MAPPER::FloorRect( UINT x, UINT y, float s )->std::shared_ptr<SRECTF>{

	return std::make_shared<SRECTF>( s*x, s*y, s, s );
}

auto MAPPER::WallRect( UINT x, UINT y, DIX d, float s, UINT n, float r )->std::shared_ptr<SRECTF>{

	const auto	t = s * r;
	const auto	p = s - t;
	const auto	w = s - t * 2;

	switch ( d ) {
	case DIX_N:return std::make_shared<SRECTF>( s*x+t, s*y,   w, t );
	case DIX_E:return std::make_shared<SRECTF>( s*x+p, s*y+t, t, w );
	case DIX_S:return std::make_shared<SRECTF>( s*x+t, s*y+p, w, t );
	case DIX_W:return std::make_shared<SRECTF>( s*x,   s*y+t, t, w );
	default:break;
	}

	return nullptr;
}

auto MAPPER::CornerRect( UINT x, UINT y, UINT c, float s, UINT n, float r )->std::shared_ptr<SRECTF>{

	const auto	t = s * r;
	const auto	p = s - t;

	switch ( c ) {
	case DIC_I:return std::make_shared<SRECTF>( s*x,   s*y,   t, t );
	case DIC_U:return std::make_shared<SRECTF>( s*x+p, s*y,   t, t );
	case DIC_T:return std::make_shared<SRECTF>( s*x+p, s*y+p, t, t );
	case DIC_H:return std::make_shared<SRECTF>( s*x,   s*y+p, t, t );
	default:break;
	}

	return nullptr;
}

// End Of File
