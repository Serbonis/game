#pragma once
//========================================
// mummy_v.hpp
//========================================
#include "enemy_v.hpp"

#include "rect3.hpp"
#include "texture.hpp"

//----------------------------------------
// MUMMY V
//----------------------------------------
class MUMMY_V final : public ENEMY_V {
private:
	RECT3	rect3;

public:
	void Init( const char* p = nullptr ) override {

		ACTOR_VIEW::Init( p );

		rect3.Open( this );

		rect3.SetSize( 4 );
		rect3.SetPivotY( 2 );
		rect3.SetPart( BILL );
		rect3.SubFlag( opal::FLAG_R );
		rect3.Parent( this );
	}

	void Free( void ) override {

		rect3.Close();

		ACTOR_VIEW::Free();
	}

	void SetTexture( const TEXTURE* t, std::shared_ptr<opal::SRECTF> r = nullptr ){

		rect3.SetTexture( t );
		if ( r ) {
			rect3.SetRect( *r );
		}
	}
};

// End Of File
