//========================================
// camera_p.cpp
//========================================
#include "camera_p.hpp"

#include "actor_x.hpp"
#include "scene_game.hpp"

//----------------------------------------
// PLATFORM
//----------------------------------------
using namespace opal;

//----------------------------------------
//----------------------------------------
void PLATFORM::Init( const char* p ){

	WORKL::Init( p );

	move_x.InitPromoterPosition();
	move_z.InitPromoterPosition();
	SetUpdater( "AXIS-X", [&]{ move_x.PromoterUpdate(); } );
	SetUpdater( "AXIS-Z", [&]{ move_z.PromoterUpdate(); } );
	move_x.SetPromoterUpdate(   [&](auto){ SetTransX( move_x.GetPromoterPosition()  );	}	);
	move_z.SetPromoterUpdate(   [&](auto){ SetTransZ( move_z.GetPromoterPosition()  );	}	);
	move_x.SetPromoterCallback( [&](auto){ SetTransX( move_x.GetPromoterPositionD() );	}	);
	move_z.SetPromoterCallback( [&](auto){ SetTransZ( move_z.GetPromoterPositionD() );	}	);
	time = SEC( 1 );
}

void PLATFORM::Free( void ){

	WORKL::Free();
}

//----------------------------------------
//----------------------------------------
void PLATFORM::SetConnect( const ACTOR_X* a ){ subject = a;	}

//----------------------------------------
//----------------------------------------
void PLATFORM::ObjFunc( void ){

	if ( subject ) {
		SetRotateY( subject->GetRotate() );

		if ( const auto p = Game::MapPoint( subject->GetTrans() ); point != p ) {
			const auto	sv = DVECTOR( GetTrans() );
			const auto	ev = DVECTOR( Game::MapVector( p ) );
			const auto	mv = []( auto m, auto s, auto e, auto t ){
								 m->SetPromoterPosition( s, e );
								 m->PromoterPlay( m->PromoterStatus() ? m->GetPromoterCount() : t );
							 };

			if ( point.x != p.x ) { mv( &move_x, sv.x, ev.x, time );	}
			if ( point.y != p.y ) { mv( &move_z, sv.y, ev.y, time );	}

			point = p;
		}
	}
}

// End Of File
