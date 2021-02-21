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
public:
	explicit ACTOR_A( ACTOR_X* = nullptr );
	virtual ~ACTOR_A();

protected:
	ACTOR_X* actor;

public:
	virtual void SetMyActor( ACTOR_X* ) final;
	virtual auto GetMyActor( void ) const->ACTOR_X* final;

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
// ROTATE
//----------------------------------------
class ACTOR_A_ROTATE : public ACTOR_A {
	using ACTOR_A::ACTOR_A;

private:
	float	speed;

public:
	virtual void RotateL( void  );
	virtual void RotateR( void  );
	virtual void RotateL( float );
	virtual void RotateR( float );

	virtual void SetRotateSpeed( float );
	virtual auto GetRotateSpeed( void ) const->float;
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

//----------------------------------------
// SPELL
//----------------------------------------
class ACTOR_A_SPELL : public ACTOR_A {
	using ACTOR_A::ACTOR_A;

private:
	float			speed;
	float			power;
	opal::VECTOR3	pivot;

public:
	virtual void SetSpellSpeed( float );
	virtual auto GetSpellSpeed( void ) const->float;

	virtual void SetSpellPower( float );
	virtual auto GetSpellPower( void ) const->float;

	virtual void SetSpellPivot( float, float, float );
	virtual void SetSpellPivot( float, float );
	virtual void SetSpellPivot( float );
	virtual auto GetSpellPivot( void ) const->opal::VECTOR3;
};

// End Of File
