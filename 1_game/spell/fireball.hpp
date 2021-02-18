#pragma once
//========================================
// fireball.hpp
//========================================
#include "spell_x.hpp"

//----------------------------------------
// SPELL FIREBALL
//----------------------------------------
class FIREBALL_C :
	public ACTOR_C<>
{
	using ACTOR_C::ACTOR_C;
};

class SPELL_FIREBALL :
	public SPELL_X,
	public FIREBALL_C
{
public:
	explicit SPELL_FIREBALL( SPELL_KIND, void* = nullptr );

public:
	virtual void Init( const char* = nullptr ) override;
	virtual void Free( void ) override;

public:
	virtual void SetTexture( const class TEXTURE*, std::shared_ptr<opal::SRECTF> = nullptr ) override;

private:
	auto fsm_move( FSM_ARGP )->FSM_RETV;
};

// End Of File
