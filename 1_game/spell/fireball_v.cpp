//========================================
// fireball_v.cpp
//========================================
#include "fireball_v.hpp"

//----------------------------------------
// FIREBALL V
//----------------------------------------
using namespace opal;

//----------------------------------------
//----------------------------------------
void FIREBALL_V::Init( const char* p ){

	ACTOR_VIEW::Init( p );

	rect3.Open( this );

	rect3.SetSize( 1 );
	rect3.SetPivotY( 2 );
	rect3.SetPart( BILL );
	rect3.SubFlag( FLAG_R );
	rect3.Parent( this );
}

void FIREBALL_V::Free( void ){

	rect3.Close();

	ACTOR_VIEW::Free();
}

void FIREBALL_V::SetTexture( const TEXTURE* t, std::shared_ptr<SRECTF> r ){

	rect3.SetTexture( t );
	if ( r ) {
		rect3.SetRect( *r );
	}
}

// End Of File
