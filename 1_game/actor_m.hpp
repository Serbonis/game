#pragma once
//========================================
// actor_m.hpp
//========================================
#include "actor_s.hpp"

//----------------------------------------
// ACTOR_M
//----------------------------------------
struct ACTOR_W {
	int		hp_val	= 0;
	int		hp_max	= 0;
	int		mp_val	= 0;
	int		mp_max	= 0;

	float	size	= 0;

	UINT	stat	= ACTOR_STAT::Undef;

	int		position_x;
	int		position_y;
	int		direction;
};

class ACTOR_M : protected ACTOR_W {
public:
	virtual void SetValHP( int );
	virtual void SetValMP( int );
	virtual void SetMaxHP( int );
	virtual void SetMaxMP( int );
	virtual auto GetValHP( void ) const->int;
	virtual auto GetValMP( void ) const->int;
	virtual auto GetMaxHP( void ) const->int;
	virtual auto GetMaxMP( void ) const->int;

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
