//========================================
// actor_x.cpp
//========================================
#include "actor_x.hpp"

//----------------------------------------
// ACTOR_X
//----------------------------------------
using namespace opal;

//----------------------------------------
// constructor & destructor
//----------------------------------------
ACTOR_X::ACTOR_X( void* p ) :
	ACTOR{p},
	ACTOR_M{}
{}

//----------------------------------------
// èâä˙âªÅïå„énññ
//----------------------------------------
void ACTOR_X::Init( const char* p ){

	ACTOR::Init( p );
	SetDim3( true );
}

void ACTOR_X::Free( void ){

	ACTOR::Free();
}

// End Of File
