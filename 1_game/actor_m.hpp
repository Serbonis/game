#pragma once
//========================================
// actor_m.hpp
//========================================
#include "actor_s.hpp"

//----------------------------------------
// ACTOR_M
//----------------------------------------
struct ACTOR_W {
	int			hitpoints	= 0;
	float		size		= 0;

	UINT		stat		= ACTOR_STAT::Undef;
};

class ACTOR_M : protected ACTOR_W {
public:
	virtual void SetStat( UINT s = ACTOR_STAT::Undef ){ stat = s;	}
	virtual auto GetStat( void ) const->UINT{ return stat;	}
};

// End Of File
