//========================================
// enemy_x.cpp
//========================================
#include "enemy_x.hpp"

//----------------------------------------
// ENEMY X
//----------------------------------------
using namespace opal;

//----------------------------------------
// constructor & destructor
//----------------------------------------
ENEMY_X::ENEMY_X( ENEMY_KIND k, void* g ) :
	ACTOR_X{g},
	ENEMY_M{k},
	ENEMY_C{this}
{}

//----------------------------------------
//----------------------------------------
void ENEMY_X::Init( const char* p ){

	ACTOR_X::Init( p );

	PRIMS::MakeSharedPrim( view );

	SetUpdater( "ACTOR_C", [&]{ ACTOR_C::Updater( this ); } );
}

//----------------------------------------
//----------------------------------------
void ENEMY_X::Free( void ){

	ACTOR_X::Free();
}

//----------------------------------------
//----------------------------------------
void ENEMY_X::ObjFunc( void ){}

// End Of File
