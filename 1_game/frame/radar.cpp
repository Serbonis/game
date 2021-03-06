//========================================
// radar.cpp
//========================================
#include "radar.hpp"
#include "radar_v.hpp"

//----------------------------------------
// FRAME - RADAR
//----------------------------------------
using namespace opal;
using namespace LAYOUT;

//----------------------------------------
//----------------------------------------
void FRAME_RADAR::Init( const char* p ){

	DRAWL::Init( p );

	makeshared( view );

	view->Open( this );
	view->Parent( this );
}

void FRAME_RADAR::Free( void ){

	if ( view ) {
		view->Close();
		view = nullptr;
	}

	DRAWL::Free();
}

//----------------------------------------
//----------------------------------------
void FRAME_RADAR::Clear( void ){

	MAPPER_VIEW::Clear();

	view->WakuColor(  FRAME_RADAR_WAKU_COLOR[0]  );
	view->ArrowColor( FRAME_RADAR_ARROW_COLOR[0] );
}

//----------------------------------------
//----------------------------------------
void FRAME_RADAR::Move( UINT x, UINT y ){

	view->Move( x, size.h-1 - y );
}

void FRAME_RADAR::Turn( float r ){

	view->Turn( r );
}

//----------------------------------------
//----------------------------------------
void FRAME_RADAR::ObjFunc( void ){}

//----------------------------------------
//----------------------------------------
#if OPAL_DEBUG
void FRAME_RADAR::Debug( void ) const {}
#endif

// End Of File

