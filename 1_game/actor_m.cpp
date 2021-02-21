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
void ACTOR_M::SetPosition( float x, float z, float h ){}
void ACTOR_M::SetPosition( float x, float z ){}
void ACTOR_M::SetDirection( float d ){}

// End Of File
