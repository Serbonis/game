#pragma once
//========================================
// player_x.hpp
//========================================
#include "actor_x.hpp"
#include "player_m.hpp"

//----------------------------------------
// PLAYER X
//----------------------------------------
class PLAYER_C :
	public ACTOR_C<ACTOR_A_MOVE,ACTOR_A_TURN,ACTOR_A_JUMP,ACTOR_A_SPELL>
{};

class PLAYER_X :
	public ACTOR_X,
	public PLAYER_M,
	public PLAYER_C
{
public:
	explicit PLAYER_X() = default;
	virtual ~PLAYER_X() = default;

public:
	virtual void Init( const char* = nullptr ) override;
	virtual void Free( void ) override;

private:
	virtual void ObjFunc( void ) override;

public:
	virtual void SetTexture( const class TEXTURE*, std::shared_ptr<opal::SRECTF> = nullptr );

private:
	using PLAYER_M::Spell;

public:
	virtual void FireBall( float, float );
	virtual void FireBall( float );
	virtual void FireBall( void );

private:
	virtual void atari_func( const std::string&,const ATARIC*,
							 const std::string&,const ATARIC* );
};

// End Of File
