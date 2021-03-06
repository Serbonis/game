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
PLAYER_X::PLAYER_X( UINT n ) :
	index{n}
{}

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
void PLAYER_X::SetPlayerParam( const PLAYER_PARAM& p ){

	PLAYER_M::SetPlayerParam( p );
	PLAYER_C::SetMoveSpeed( p.move.speed );
	PLAYER_C::SetTurnSpeed( p.turn.speed );
	PLAYER_C::SetJumpSpeed( p.jump.speed );
}

//----------------------------------------
//----------------------------------------
void PLAYER_X::SetMoveSpeed( float s ){

	PLAYER_M::SetMoveSpeed( s );
	PLAYER_C::SetMoveSpeed( s );
}

auto PLAYER_X::GetMoveSpeed( void ) const->float{

	return PLAYER_M::GetMoveSpeed();
}

void PLAYER_X::SetTurnSpeed( float s ){

	PLAYER_M::SetTurnSpeed( s );
	PLAYER_C::SetTurnSpeed( s );
}

auto PLAYER_X::GetTurnSpeed( void ) const->float{

	return PLAYER_M::GetTurnSpeed();
}

void PLAYER_X::SetJumpSpeed( float s ){

	PLAYER_M::SetJumpSpeed( s );
	PLAYER_C::SetJumpSpeed( s );
}

auto PLAYER_X::GetJumpSpeed( void ) const->float{

	return PLAYER_M::GetJumpSpeed();
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

	if ( CONTROLL::PlayerDebug( index ) ) {
		const auto	o = GetOffset();
		const auto	[px,py] = GetPosition();
		const auto	d = GetDirection();

		printd( "PLAYER[%d]\n", index );
		printd( "POS [%02d,%02d]\n", px, py );
		printd( "DIR [%c]\n", "NESW"[d] );
		printd( "F[A/D] : %f, %f\n", o.x, o.y );
		printd( "B[W/S] : %f\n", GetMoveSpeed() );
		printd( "R[Q/E] : %f\n", DEG( GetTurnSpeed() ) );
		printd( "H[SPC] : %f\n", o.h );
		printd( "\n" );
	}
#endif

	if ( CONTROLL::PlayerMoveF( index ) ) { MoveF();	}
	if ( CONTROLL::PlayerMoveB( index ) ) { MoveB();	}
	if ( CONTROLL::PlayerMoveL( index ) ) { MoveL();	}
	if ( CONTROLL::PlayerMoveR( index ) ) { MoveR();	}
	if ( CONTROLL::PlayerTurnL( index ) ) { TurnL(); 	}
	if ( CONTROLL::PlayerTurnR( index ) ) { TurnR(); 	}
	if ( CONTROLL::PlayerJump(  index ) ) { Jump();		}

	if ( CONTROLL::PlayerFireBall( index ) ) { FireBall();	}
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
