//========================================
// actor_a.cpp
//========================================
#include "actor_a.hpp"
#include "actor_x.hpp"

//----------------------------------------
// ACTOR_A
//----------------------------------------
using namespace opal;

//----------------------------------------
// constructor & destructor
//----------------------------------------
ACTOR_A::ACTOR_A( ACTOR_X* a ) :
	actor{a}
{
	FSM::InitFSM( "FSM" );
	FSM::GenerateActor( "FSM" );
	FSM::SetActor( "FSM", "fsm" );
}

ACTOR_A::~ACTOR_A()
{
	FSM::DestroyActor();
	FSM::FreeFSM();
}

//----------------------------------------
// Actor
//----------------------------------------
void ACTOR_A::SetMyActor( ACTOR_X* a ){ actor = a;	}
auto ACTOR_A::GetMyActor( void ) const->ACTOR_X*{ return actor;	}

//----------------------------------------
// Updater
//----------------------------------------
void ACTOR_A::Updater( ACTOR_X* a ){

	if ( actor != a ) { actor = a; }

	FSM::ExecFSM( actor );
}

//----------------------------------------
// MOVE
//----------------------------------------
void ACTOR_A_MOVE::MoveF( void ){ MoveF( speed );	}
void ACTOR_A_MOVE::MoveB( void ){ MoveB( speed );	}
void ACTOR_A_MOVE::MoveL( void ){ MoveL( speed );	}
void ACTOR_A_MOVE::MoveR( void ){ MoveR( speed );	}
void ACTOR_A_MOVE::MoveF( float s ){ const auto [x,z] = moveF( actor->GetRotate(), s ); actor->AddTrans( x, 0, z ); }
void ACTOR_A_MOVE::MoveB( float s ){ const auto [x,z] = moveB( actor->GetRotate(), s ); actor->AddTrans( x, 0, z ); }
void ACTOR_A_MOVE::MoveL( float s ){ const auto [x,z] = moveL( actor->GetRotate(), s ); actor->AddTrans( x, 0, z ); }
void ACTOR_A_MOVE::MoveR( float s ){ const auto [x,z] = moveR( actor->GetRotate(), s ); actor->AddTrans( x, 0, z ); }

void ACTOR_A_MOVE::SetMoveSpeed( float s ){ speed = s;	}
auto ACTOR_A_MOVE::GetMoveSpeed( void ) const->float{ return speed;	}

//----------------------------------------
// TURN
//----------------------------------------
void ACTOR_A_TURN::TurnL( void ){ TurnL( speed );	}
void ACTOR_A_TURN::TurnR( void ){ TurnR( speed );	}

void ACTOR_A_TURN::SetTurnSpeed( float s ){ speed = s;	}
auto ACTOR_A_TURN::GetTurnSpeed( void ) const->float{ return speed;	}

struct FSM_TURN : public FSM_FUNCTION {
	FSM_TURN() = delete;
	FSM_TURN( float s, float rs, float rd ) :
		speed{s},
		rd{rd},
		rs{rs}
	{};

	const float	speed;
	const float	rd;
	float		rs;
};

float DistinationL( float d ){

	const auto	rd = NormalRadian360( d );

	if ( RAD(   0 ) < rd && rd < RAD(  90 ) ) { return RAD(   0 );	}
	if ( RAD(  90 ) < rd && rd < RAD( 180 ) ) { return RAD(  90 );	}
	if ( RAD( 180 ) < rd && rd < RAD( 270 ) ) { return RAD( 180 );	}
	if ( RAD( 270 ) < rd && rd < RAD( 360 ) ) { return RAD( 270 );	}

	if ( FEQU( rd, RAD(   0 ) ) ) { return RAD( -90 );	}
	if ( FEQU( rd, RAD(  90 ) ) ) { return RAD(   0 );	}
	if ( FEQU( rd, RAD( 180 ) ) ) { return RAD(  90 );	}
	if ( FEQU( rd, RAD( 270 ) ) ) { return RAD( 180 );	}

	return d;
}

float DistinationR( float d ){

	const auto	rd = NormalRadian360( d );

	if ( RAD(   0 ) < rd && rd < RAD(  90 ) ) { return RAD(  90 );	}
	if ( RAD(  90 ) < rd && rd < RAD( 180 ) ) { return RAD( 180 );	}
	if ( RAD( 180 ) < rd && rd < RAD( 270 ) ) { return RAD( 270 );	}
	if ( RAD( 270 ) < rd && rd < RAD( 360 ) ) { return RAD( 360 );	}

	if ( FEQU( rd, RAD(   0 ) ) ) { return RAD(  90 );	}
	if ( FEQU( rd, RAD(  90 ) ) ) { return RAD( 180 );	}
	if ( FEQU( rd, RAD( 180 ) ) ) { return RAD( 270 );	}
	if ( FEQU( rd, RAD( 270 ) ) ) { return RAD( 360 );	}

	return d;
}

void ACTOR_A_TURN::TurnL( float s ){

	const auto	rs = NormalRadian360( actor->GetRotate() );
	const auto	rd = DistinationL( rs );

	FSM::SetActor( "FSM" );
	FSM::SetAction<FSM_TURN>( "fsm", FSM_BIND( this, &ACTOR_A_TURN::fsm_turnL ), s, rs, rd );
}

void ACTOR_A_TURN::TurnR( float s ){

	const auto	rs = NormalRadian360( actor->GetRotate() );
	const auto	rd = DistinationR( rs );

	FSM::SetActor( "FSM" );
	FSM::SetAction<FSM_TURN>( "fsm", FSM_BIND( this, &ACTOR_A_TURN::fsm_turnR ), s, rs, rd );
}

auto ACTOR_A_TURN::fsm_turnL( FSM_ARGP a )->FSM_RETV{

	const auto	work = FSM_WORK<FSM_TURN>( a );
	auto& speed	= work->speed;
	auto& rs	= work->rs;
	auto& rd	= work->rd;

	if ( FLSS( rs -= speed, rd ) ) {
		actor->SetRotate( NormalRadian360( rd ) );
		return FSM_BREAK();
	} else {
		actor->SetRotate( rs );
		return FSM_CONTINUE{};
	}
}

auto ACTOR_A_TURN::fsm_turnR( FSM_ARGP a )->FSM_RETV{

	const auto	work = FSM_WORK<FSM_TURN>( a );
	auto& speed	= work->speed;
	auto& rs	= work->rs;
	auto& rd	= work->rd;

	if ( FGRT( rs += speed, rd ) ) {
		actor->SetRotate( NormalRadian360( rd ) );
		return FSM_BREAK();
	} else {
		actor->SetRotate( rs );
		return FSM_CONTINUE{};
	}
}

//----------------------------------------
// JUMP
//----------------------------------------
void ACTOR_A_JUMP::Jump( void ){ Jump( speed );	}
void ACTOR_A_JUMP::Jump( float s ){}

auto ACTOR_A_JUMP::fsm_jump( FSM_ARGP a )->FSM_RETV{

	return FSM_CONTINUE();
}

// End Of File
