//========================================
// aobj_cylinder.cpp
//========================================
#include "aobj_cylinder.hpp"

//----------------------------------------
// AOBJ_CYLINDER
//----------------------------------------
using namespace opal;

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

// End Of File
