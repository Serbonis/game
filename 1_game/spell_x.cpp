//========================================
// spell_x.cpp
//========================================
#include "spell_x.hpp"

//----------------------------------------
// SPELL X
//----------------------------------------
using namespace opal;

//----------------------------------------
// constructor & destructor
//----------------------------------------
SPELL_X::SPELL_X( SPELL_KIND k, void* g ) :
	ACTOR_X{g},
	SPELL_M{k},
	SPELL_C{this}
{}

//----------------------------------------
//----------------------------------------
void SPELL_X::Init( const char* p ){

	ACTOR_X::Init( p );

	PRIMS::MakeSharedPrim( view );

	SetUpdater( "ACTOR_C", [&]{ ACTOR_C::Updater( this ); } );
}

//----------------------------------------
//----------------------------------------
void SPELL_X::Free( void ){

	ACTOR_X::Free();
}

//----------------------------------------
//----------------------------------------
void SPELL_X::ObjFunc( void ){}

// End Of File
