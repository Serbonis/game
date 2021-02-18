#pragma once
//========================================
// actor_x.hpp
//========================================
#include "actor.hpp"
#include "actor_m.hpp"
#include "actor_c.hpp"
#include "actor_a.hpp"
#include "fsm.hpp"

//----------------------------------------
// ACTOR_X
//----------------------------------------
class ACTOR_X :
	public ACTOR,
	public ACTOR_M,
	public FSM
{
public:
	explicit ACTOR_X( void* = nullptr );
	virtual ~ACTOR_X() = default;

public:
	virtual void Init( const char* = nullptr ) override;
	virtual void Free( void ) override;
};

// End Of File
