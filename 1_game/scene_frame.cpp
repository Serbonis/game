//========================================
// scene_frame.cpp
//========================================
#include "scene_frame.hpp"
#include "scene_game.hpp"

#include "frame/viewport.hpp"
#include "frame/scissor.hpp"
#include "frame/minimap.hpp"
#include "frame/radar.hpp"
#include "frame/status.hpp"

#include "actor_x.hpp"

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
	makeshared( radar    );
	makeshared( status   );

	minimap->Open( "MINIMAP", this );
	minimap->SetTrans( FRAME_MINIMAP_X, FRAME_MINIMAP_Y );
	minimap->Parent( this );

	radar->Open( "RADAR", this );
	radar->SetTrans( FRAME_RADAR_X, FRAME_RADAR_Y );
	radar->Parent( this );

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
	radar->Close();
	minimap->Close();

	scissor->end.Close();
	scissor->begin.Close();
	viewport->end.Close();
	viewport->begin.Close();

	viewport = nullptr;
	scissor  = nullptr;
	minimap  = nullptr;
	radar    = nullptr;
	status   = nullptr;

	DRAWL::Free();
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
		radar->Debug();
		status->Debug();
	}
#endif

	for ( const auto& [n,a] : actor ) {
		if ( !a.expired() ) {
			const auto	p = a.lock();

			StatusValHP( n, p->GetValHP() );
			StatusValMP( n, p->GetValMP() );
			StatusMaxHP( n, p->GetMaxHP() );
			StatusMaxMP( n, p->GetMaxMP() );
		}
	}
}

//----------------------------------------
//----------------------------------------
void SCENE_FRAME::GenerateStatus( UINT n ){

	status->Generate( n );
}

void SCENE_FRAME::GenerateStatus( UINT n, std::weak_ptr<const ACTOR_X> p ){

	GenerateStatus( n );
	SetConnect( n, p );
}

void SCENE_FRAME::DestroyStatus( UINT n ){

	status->Destroy( n );
}

//----------------------------------------
//----------------------------------------
void SCENE_FRAME::SetConnect( UINT n, std::weak_ptr<const ACTOR_X> p ){

	if ( p.expired() ) {
		maperase( actor, n );
	} else {
		actor[n] = p;
	}
}

auto SCENE_FRAME::GetConnect( UINT n ) const->std::weak_ptr<const ACTOR_X>{

	if ( const auto p = mapped( actor, n ); !p.expired() ) {
		return p;
	}
	return {};
}

//----------------------------------------
//----------------------------------------
void SCENE_FRAME::StatusName(  UINT n, const std::string& s ){ status->Name( n, s );	}
void SCENE_FRAME::StatusName(  UINT n ){ status->Name( n );	}

void SCENE_FRAME::StatusFace(  UINT n, TEXTURE* t ){ status->Face( n, t );	}

void SCENE_FRAME::StatusValHP( UINT n ){ status->ValHP( n );	}
void SCENE_FRAME::StatusValHP( UINT n, float v, bool f ){ status->ValHP( n, v, f );	}
void SCENE_FRAME::StatusValMP( UINT n, float v, bool f ){ status->ValMP( n, v, f );	}
void SCENE_FRAME::StatusMaxHP( UINT n, float m ){ status->MaxHP( n, m );	}
void SCENE_FRAME::StatusMaxMP( UINT n, float m ){ status->MaxMP( n, m );	}

// End Of File
