//========================================
// grid_v.cpp
//========================================
#include "grid_v.hpp"
#include "grid_r.hpp"

//----------------------------------------
// GRID V
//----------------------------------------
using namespace opal;

//----------------------------------------
//----------------------------------------
void GRID_V::Init( const char* p ){

	DRAW3L::Init( p );

	c.Open( this );
	c.Parent( this );
	c.SetDisp( false );
	c.SetAxis( AXIS_MY );

	f.Open( this );
	f.Parent( this );
	f.SetDisp( false );
	f.SetAxis( AXIS_PY );

	for ( auto i = 0; i < DIX_MAX; i++ ) {
		w[i].Open( this );
		w[i].Parent( this );
		w[i].SetDisp( false );
	}
	w[DIX_N].SetAxis( AXIS_MZ );
	w[DIX_S].SetAxis( AXIS_PZ );
	w[DIX_E].SetAxis( AXIS_MX );
	w[DIX_W].SetAxis( AXIS_PX );
}

void GRID_V::Free( void ){

	for ( auto i = 0; i < DIX_MAX; i++ ) {
		w[i].Close();
	}
	f.Close();
	c.Close();

	DRAW3L::Free();
}

//----------------------------------------
//----------------------------------------
float GRID_V::operator =( float s ){

	c.SetSize( s );
	c.SetPivot();
	c.SetTransY( +s );

	f.SetSize( s );
	f.SetPivot();
	f.SetTransY();

	for ( auto i = 0; i < DIX_MAX; i++ ) {
		w[i].SetSize( s );
		w[i].SetPivot();
		w[i].SetTransY( +s/2 );
	}

	w[DIX_N].SetTransZ( +s/2 );
	w[DIX_S].SetTransZ( -s/2 );
	w[DIX_E].SetTransX( +s/2 );
	w[DIX_W].SetTransX( -s/2 );

	return s;
}

//----------------------------------------
//----------------------------------------
template<typename PRIM, typename KIND>void SetTexture( PRIM& p, KIND k ){

	if ( k != decltype( k )::Undef ) {
		p.SetDisp( true );
		p.SetTexture( RESOURCE::GRID::Texture( k ) );
	} else {
		p.SetDisp( false );
		p.SetTexture( nullptr );
	}
}

void GRID_V::SetFloor( GRID_KIND_FLOOR k ){ SetTexture( f, k );	}
void GRID_V::SetCeil(  GRID_KIND_CEIL  k ){ SetTexture( c, k );	}
void GRID_V::SetWall( DIX d, GRID_KIND_WALL k ){

	switch ( d ){
	default:return;
	case DIX_N:break;
	case DIX_S:break;
	case DIX_E:break;
	case DIX_W:break;
	}

	SetTexture( w[d], k );
}

// End Of File
