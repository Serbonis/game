#pragma once
//========================================
// actor_m.hpp
//========================================
#include "actor_s.hpp"

//----------------------------------------
// ACTOR_M
//----------------------------------------
struct ACTOR_W {
	int		hitpoints	= 0;

	float	size	= 0;

	UINT	stat	= ACTOR_STAT::Undef;

	int		position_x;
	int		position_y;
	int		direction;
};

class ACTOR_M : protected ACTOR_W {
public:
	virtual void SetStat( UINT = ACTOR_STAT::Undef );
	virtual auto GetStat( void ) const->UINT;

public:
	virtual void SetPosition( int, int );
	virtual void SetDirection( int );

public:
	virtual auto GetPosition(  void ) const->std::pair<int,int>;
	virtual auto GetDirection( void ) const->int;
};

// End Of File
