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
private:
	explicit PLAYER_X() = delete;

public:
	explicit PLAYER_X( UINT );
	virtual ~PLAYER_X() = default;

protected:
	UINT	index;

public:
	virtual void Init( const char* = nullptr ) override;
	virtual void Free( void ) override;

private:
	virtual void ObjFunc( void ) override;

public:
	virtual void SetTexture( const class TEXTURE*, std::shared_ptr<opal::SRECTF> = nullptr );

public:
	virtual void SetPlayerParam( const PLAYER_PARAM& ) override;

public:
	virtual void SetMoveSpeed( float ) override;
	virtual auto GetMoveSpeed( void ) const->float override;

	virtual void SetTurnSpeed( float ) override;
	virtual auto GetTurnSpeed( void ) const->float override;

	virtual void SetJumpSpeed( float ) override;
	virtual auto GetJumpSpeed( void ) const->float override;

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
