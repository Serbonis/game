#pragma once
//========================================
// actor_a.hpp
//========================================
#include "fsm.hpp"

//----------------------------------------
// ACTOR_A
//----------------------------------------
class ACTOR_X;
class ACTOR_A : public FSM {
private:
	explicit ACTOR_A() = delete;

public:
	explicit ACTOR_A( ACTOR_X* );
	virtual ~ACTOR_A();

protected:
	ACTOR_X* const actor;

public:
	virtual void Updater( ACTOR_X* );
};

//----------------------------------------
// MOVE
//----------------------------------------
class ACTOR_A_MOVE : public ACTOR_A {
	using ACTOR_A::ACTOR_A;

private:
	float	speed;

public:
	virtual void MoveF( void  );
	virtual void MoveB( void  );
	virtual void MoveL( void  );
	virtual void MoveR( void  );
	virtual void MoveF( float );
	virtual void MoveB( float );
	virtual void MoveL( float );
	virtual void MoveR( float );

	virtual void SetMoveSpeed( float );
	virtual auto GetMoveSpeed( void ) const->float;
};

//----------------------------------------
// TURN
//----------------------------------------
class ACTOR_A_TURN : public ACTOR_A {
	using ACTOR_A::ACTOR_A;

private:
	float	speed;

public:
	virtual void TurnL( void  );
	virtual void TurnR( void  );
	virtual void TurnL( float );
	virtual void TurnR( float );

	virtual void SetTurnSpeed( float );
	virtual auto GetTurnSpeed( void ) const->float;

protected:
	virtual auto fsm_turnL( FSM_ARGP )->FSM_RETV;
	virtual auto fsm_turnR( FSM_ARGP )->FSM_RETV;
};

//----------------------------------------
// JUMP
//----------------------------------------
class ACTOR_A_JUMP : public ACTOR_A {
	using ACTOR_A::ACTOR_A;

private:
	float	speed;

public:
	virtual void Jump( void  );
	virtual void Jump( float );

protected:
	virtual auto fsm_jump( FSM_ARGP )->FSM_RETV;
};

// End Of File
