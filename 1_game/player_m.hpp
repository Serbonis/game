#pragma once
//========================================
// player_m.hpp
//========================================
#include "actor_m.hpp"
#include "player.hpp"

//----------------------------------------
// PLAYER M
//----------------------------------------
enum class SPELL_KIND;

class PLAYER_M :
	protected virtual ACTOR_M,
	protected PLAYER
{
	using PLAYER::PLAYER;

public:
	virtual auto Kind( void ) const->PLAYER_KIND final;

public:
	virtual void SetName( const std::string& );
	virtual void SetName( void );
	virtual auto GetName( void ) const->std::string;

public:
	virtual void SetPlayerParam( const PLAYER_PARAM& );
	virtual auto GetPlayerParam( void ) const->PLAYER_PARAM;

public:
	virtual void SetMoveSpeed( float );
	virtual auto GetMoveSpeed( void ) const->float;

	virtual void SetTurnSpeed( float );
	virtual auto GetTurnSpeed( void ) const->float;

	virtual void SetJumpSpeed( float );
	virtual auto GetJumpSpeed( void ) const->float;

public:
	virtual void Spell( SPELL_KIND, float, float, float, float, float, float ) final;
};

// End Of File
