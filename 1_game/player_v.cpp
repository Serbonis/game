//========================================
// player_v.cpp
//========================================
#include "player_v.hpp"

//----------------------------------------
// PLAYER V
//----------------------------------------
using namespace opal;

//----------------------------------------
//----------------------------------------
void PLAYER_V::Init( const char* p ){

	ACTOR_VIEW::Init( p );

	rect3.Open( this );

	rect3.SetSize( 2 );
	rect3.SetPivotY( 1 );
	rect3.SetPart( BILL );
	rect3.SubFlag( FLAG_R );
	rect3.Parent( this );
}

//----------------------------------------
//----------------------------------------
void PLAYER_V::Free( void ){

	rect3.Close();

	ACTOR_VIEW::Free();
}

//----------------------------------------
//----------------------------------------
void PLAYER_V::SetTexture( const TEXTURE* t, std::shared_ptr<opal::SRECTF> r ){

	rect3.SetTexture( t );
	if ( r ) {
		rect3.SetRect( *r );
	}
}

// End Of File
