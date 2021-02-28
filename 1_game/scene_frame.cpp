//========================================
// scene_frame.cpp
//========================================
#include "scene_frame.hpp"
#include "scene_game.hpp"

#include "frame/viewport.hpp"
#include "frame/scissor.hpp"
#include "frame/minimap.hpp"
#include "frame/status.hpp"

#include "layout.hpp"

//----------------------------------------
// SCENE_FRAME
//----------------------------------------
using namespace opal;
using namespace LAYOUT;

#if OPAL_DEBUG
static bool	debug_flag;
#endif

//----------------------------------------
//
//----------------------------------------
void SCENE_FRAME::Init( const char* p ){

	DRAWL::Init( p );
	DRAWL::SetLinxInfo( true );

	makeshared( viewport );
	makeshared( scissor  );
	makeshared( minimap  );
	makeshared( status   );

	minimap->Open( "MINIMAP", this );
	minimap->SetTrans( FRAME_MINIMAP_X, FRAME_MINIMAP_Y );
	minimap->Parent( this );

	status->Open( "STATUS", this );
	status->SetTrans( FRAME_STATUS_X, FRAME_STATUS_Y );
	status->Parent( this );

	viewport->begin.Open( "VP BEGIN", this );
	scissor->begin.Open(  "SC BEGIN", this );

	viewport->end.Open( "VP END" );
	scissor->end.Open(  "SC END" );

	viewport->begin.SetRect( FRAME_VIEWPORT_X, FRAME_VIEWPORT_Y, FRAME_VIEWPORT_W, FRAME_VIEWPORT_H );
	scissor->begin.SetRect(  FRAME_SCISSOR_X,  FRAME_SCISSOR_Y,  FRAME_SCISSOR_W,  FRAME_SCISSOR_H  );
	viewport->end.SetPrio( PRIO_MAX );
	scissor->end.SetPrio(  PRIO_MAX );

#if OPAL_DEBUG
	debug_flag = true;
#endif
}

void SCENE_FRAME::Free( void ){

	status->Close();
	minimap->Close();

	scissor->end.Close();
	scissor->begin.Close();
	viewport->end.Close();
	viewport->begin.Close();

	viewport = nullptr;
	scissor  = nullptr;
	minimap  = nullptr;
	status   = nullptr;

	DRAWL::Free();
}

//----------------------------------------
//----------------------------------------
void SCENE_FRAME::GenerateStatus( UINT n ){

	status->Generate( n );
}

void SCENE_FRAME::DestroyStatus(  UINT n ){

	status->Destroy( n );
}

//----------------------------------------
//----------------------------------------
#if OPAL_DEBUG
#include "controll.hpp"
#endif
void SCENE_FRAME::ObjFunc( void ){
#if OPAL_DEBUG
	if ( CONTROLL::FrameDebug() ) {
		FLAG_CTRL( debug_flag, FLAG_FLIP );
	}

	if ( debug_flag ) {
		status->Debug();
	}
#endif
}

// End Of File
