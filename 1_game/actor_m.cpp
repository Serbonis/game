//========================================
// actor_m.cpp
//========================================
#include "actor_m.hpp"
#include "actor_x.hpp"

//----------------------------------------
// ACTOR_M
//----------------------------------------
using namespace opal;

//----------------------------------------
//----------------------------------------
void ACTOR_M::SetStat( UINT s ){ stat = s;	}
auto ACTOR_M::GetStat( void ) const->UINT{ return stat;	}

//----------------------------------------
//----------------------------------------
void ACTOR_M::SetPosition( int x, int y ){

	position_x = x;
	position_y = y;
}

void ACTOR_M::SetDirection( int d ){

	direction = d;
}

auto ACTOR_M::GetPosition( void ) const->std::pair<int,int>{

	return { position_x,position_y };
}

auto ACTOR_M::GetDirection( void ) const->int{

	return direction;
}
// End Of File
