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

	SetMoveSpeed( 0.04f );
	SetTurnSpeed( RAD( 4.0f ) );

	SetSpellSpeed( 0.4f );
	SetSpellPower( 0 );
	SetSpellPivot( 2 );

	SetUpdater( "ACTOR_C", [&]{ ACTOR_C::Updater( this ); } );

	AtariBody<PLAYER_V>( this, 2, 2 );

	ATARIC::SetAtariOwner( this );
	ATARIC::SetAtariFuncOn( [&]( auto as, auto ac, auto bs, auto bc ){ printd( "hit player" ); } );
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
		const auto	t = GetTrans();
		const auto	p = Game::MapPoint(  t );
		const auto	v = Game::MapVector( p );

		printd( "PLAYER\n" );
		printd( "V2P [%02d,%02d]\n", p.x, p.y );
		printd( "P2V [%f,%f]\n", v.x, v.z );
		printd( "F[A/D] : %f, %f\n", t.x, t.z );
		printd( "B[W/S] : %f\n", GetMoveSpeed() );
		printd( "R[Q/E] : %f\n", DEG( GetTurnSpeed() ) );
		printd( "H[SPC] : %f\n", t.y );
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

// End Of File
