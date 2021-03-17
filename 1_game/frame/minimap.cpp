//========================================
// minimap.cpp
//========================================
#include "minimap.hpp"
#include "minimap_v.hpp"

//----------------------------------------
// FRAME - MINIMAP
//----------------------------------------
using namespace opal;
using namespace LAYOUT;

//----------------------------------------
//----------------------------------------
void FRAME_MINIMAP::Init( const char* p ){

	DRAWL::Init( p );

	makeshared( view );

	view->Open( this );
	view->Parent( this );

	size = {};
}

void FRAME_MINIMAP::Free( void ){

	if ( view ) {
		view->Close();
		view = nullptr;
	}

	DRAWL::Free();
}

//----------------------------------------
//----------------------------------------
void FRAME_MINIMAP::Clear( void ){

	MAPPER_VIEW::Clear();

	view->WakuColor(  FRAME_MINIMAP_WAKU_COLOR[0]  );
}

//----------------------------------------
//----------------------------------------
void FRAME_MINIMAP::Move( float x, float y ){

	view->Move( x, y );
}

//----------------------------------------
//----------------------------------------
void FRAME_MINIMAP::MapName( const std::string& s ){

	view->MapName( s );
}

//----------------------------------------
//----------------------------------------
void FRAME_MINIMAP::ObjFunc( void ){}

//----------------------------------------
//----------------------------------------
#if OPAL_DEBUG
void FRAME_MINIMAP::Debug( void ) const {}
#endif

// End Of File

