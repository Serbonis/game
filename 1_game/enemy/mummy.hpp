#pragma once
//========================================
// mummy.hpp
//========================================
#include "enemy_x.hpp"

//----------------------------------------
// ENEMY MUMMY
//----------------------------------------
class MUMMY_C :
	public ACTOR_C<>
{
	using ACTOR_C::ACTOR_C;
};

class ENEMY_MUMMY :
	public ENEMY_X,
	public MUMMY_C
{
public:
	explicit ENEMY_MUMMY( ENEMY_KIND, void* = nullptr );

public:
	virtual void Init( const char* = nullptr ) override;
	virtual void Free( void ) override;

public:
	virtual void SetTexture( const class TEXTURE*, std::shared_ptr<opal::SRECTF> = nullptr ) override;

private:
	auto fsm_move( FSM_ARGP )->FSM_RETV;
	auto fsm_past( FSM_ARGP )->FSM_RETV;
};

// End Of File
