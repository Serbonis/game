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

	SetUpdater( "ACTOR_C", [&]{ ACTOR_C::Updater( this ); } );
}

//----------------------------------------
//----------------------------------------
void PLAYER_X::Free( void ){

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

	Spell( SPELL_KIND::FireBall, p, s, t.x, t.z, t.y, r );
}

void PLAYER_X::FireBall( float p ){

	FireBall( p, 0 );
}

void PLAYER_X::FireBall( void ){

	FireBall( 0, 0 );
}

//----------------------------------------
//----------------------------------------
#include "pad.hpp"
#include "scene_game.hpp"

void PLAYER_X::ObjFunc( void ){

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

	if ( PADX::KeyPush( KEY_W ) ) { MoveF();	}
	if ( PADX::KeyPush( KEY_S ) ) { MoveB();	}
	if ( PADX::KeyPush( KEY_A ) ) { MoveL();	}
	if ( PADX::KeyPush( KEY_D ) ) { MoveR();	}
	if ( PADX::KeyTrig( KEY_Q ) ) { TurnL(); 	}
	if ( PADX::KeyTrig( KEY_E ) ) { TurnR(); 	}

	if ( PADX::KeyTrig( KEY_B ) ) { FireBall( 0, 0.4f );	}
	if ( PADX::KeyPush( KEY_SPACE ) ) { Jump();				}
}

// End Of File
