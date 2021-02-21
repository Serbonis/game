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

	ATARIC::AtariInit();
}

void ACTOR_X::Free( void ){

	ATARIC::AtariFree();

	ACTOR::Free();
}

//----------------------------------------
//----------------------------------------
void ACTOR_X::SetPosition( float x, float z, float h ){

	ACTOR_M::SetPosition( x, z, h );
	SetTrans( x, h, z );
}

void ACTOR_X::SetPosition( float x, float z ){

	ACTOR_M::SetPosition( x, z );
	SetTransX( x );
	SetTransZ( z );
}

void ACTOR_X::SetDirection( float d ){

	ACTOR_M::SetDirection( d );
	SetRotate( Dix2Rad( d ) );
}

void ACTOR_X::SetPosition( void ){

	const auto	[x,y,z] = GetTrans();

	SetPosition( x, z, y );
}

void ACTOR_X::SetDirection( void ){

	SetDirection( GetRotate() );
}

// End Of File
