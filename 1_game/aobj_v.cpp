//========================================
// aobj_v.cpp
//========================================
#include "aobj_v.hpp"

//----------------------------------------
// AOBJ V
//----------------------------------------
using namespace opal;

//----------------------------------------
// AOBJ_CYLINDER
//----------------------------------------
void AOBJ_CYLINDER::Init( const char* p ){

	DRAWL::Init( p );

	height.Open( this );
	height.Parent( this );

	bottom.Open( this );
	bottom.SetAxis( AXIS_PY );
	bottom.Parent( this );
}

void AOBJ_CYLINDER::Free( void ){

	bottom.Close();
	height.Close();

	DRAWL::Free();
}

void AOBJ_CYLINDER::SetColor( opal::COLOR c ){

	height.SetColor( c );
	bottom.SetColor( c );
}

void AOBJ_CYLINDER::SetHeight( float s ){ height.SetLine( 0, s, 0 );	}
void AOBJ_CYLINDER::SetBottom( float s ){ bottom.SetSize( s );			}

//----------------------------------------
// AOBJ_SPHERE
//----------------------------------------
void AOBJ_SPHERE::Init( const char* p ){

	DRAWL::Init( p );

	for ( auto& a: axis ) {
		a.Open( this );
		a.Parent( this );
	}

	axis[0].SetAxis( AXIS_PX );
	axis[1].SetAxis( AXIS_PY );
	axis[2].SetAxis( AXIS_PZ );
}

void AOBJ_SPHERE::Free( void ){

	for ( auto& a: axis ) {
		a.Close();
	}

	DRAWL::Free();
}

void AOBJ_SPHERE::SetColor( opal::COLOR c ){

	for ( auto& a: axis ) {
		a.SetColor( c );
	}
}

void AOBJ_SPHERE::SetSize( float s ){

	for ( auto& a: axis ) {
		a.SetSize( s );
	}
}

// End Of File
