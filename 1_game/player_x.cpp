//========================================
// player_x.cpp
//========================================
#include "player_x.hpp"
#include "player_v.hpp"

//----------------------------------------
// PLAYER X
//----------------------------------------
using namespace opal;

//----------------------------------------
//----------------------------------------
void PLAYER_X::Init( const char* p ){

	ACTOR_X::Init( p );

	SetView<PLAYER_V>();

	SetUpdater( "ACTOR_C", [&]{ ACTOR_C::Updater( this ); } );

	AtariBody<PLAYER_V>( this, 2, 2 );

	ATARIC::SetAtariOwner( this );
	ATARIC::SetAtariFuncOn( ATARI_BIND( this, &PLAYER_X::atari_func ) );
}

//----------------------------------------
//----------------------------------------
void PLAYER_X::Free( void ){

	ATARIC::AtariDestroy();

	SetView();

	ACTOR_X::Free();
}

//----------------------------------------
//----------------------------------------
void PLAYER_X::SetTexture( const class TEXTURE* t, std::shared_ptr<opal::SRECTF> r ){

	GetView<PLAYER_V>()->SetTexture( t, r );
}

//----------------------------------------
//----------------------------------------
#include "spell_k.hpp"

void PLAYER_X::FireBall( float p, float s ){

	const auto	t = GetTrans();
	const auto	r = GetRotate();
	const auto	v = VectorRotate( GetSpellPivot(), r );

	Spell( SPELL_KIND::FireBall, p, s, t.x+v.x, t.z+v.z, t.y+v.y, r );
}

void PLAYER_X::FireBall( float p ){

	FireBall( p, GetSpellSpeed() );
}

void PLAYER_X::FireBall( void ){

	FireBall( GetSpellPower() );
}

//----------------------------------------
//----------------------------------------
#if OPAL_DEBUG
#include "scene_game.hpp"
#endif

#include "controll.hpp"

void PLAYER_X::ObjFunc( void ){

#if OPAL_DEBUG
	if ( CONTROLL::CameraDebug() ) {
		return;
	}

	if ( CONTROLL::PlayerDebug() ) {
		const auto	o = GetOffset();
		const auto	[px,py] = GetPosition();
		const auto	d = GetDirection();

		printd( "PLAYER\n" );
		printd( "POS [%02d,%02d]\n", px, py );
		printd( "DIR [%c]\n", "NESW"[d] );
		printd( "F[A/D] : %f, %f\n", o.x, o.y );
		printd( "B[W/S] : %f\n", GetMoveSpeed() );
		printd( "R[Q/E] : %f\n", DEG( GetTurnSpeed() ) );
		printd( "H[SPC] : %f\n", o.h );
		printd( "\n" );
	}
#endif

	if ( CONTROLL::PlayerMoveF() ) { MoveF();	}
	if ( CONTROLL::PlayerMoveB() ) { MoveB();	}
	if ( CONTROLL::PlayerMoveL() ) { MoveL();	}
	if ( CONTROLL::PlayerMoveR() ) { MoveR();	}
	if ( CONTROLL::PlayerTurnL() ) { TurnL(); 	}
	if ( CONTROLL::PlayerTurnR() ) { TurnR(); 	}
	if ( CONTROLL::PlayerJump()  ) { Jump();	}

	if ( CONTROLL::PlayerFireBall() ) { FireBall();	}
}

//----------------------------------------
//----------------------------------------
void PLAYER_X::atari_func( const std::string& as,const ATARIC* ac,
						   const std::string& bs,const ATARIC* bc ){

	if ( bs == "ENEMY" || bs == "E_SHOT" ) {
		printd( "DAMAGE\n" );
	}
}

// End Of File
