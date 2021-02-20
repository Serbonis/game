#pragma once
//========================================
// aobj.hpp
//========================================
#include "drawx.hpp"

//----------------------------------------
// AOBJ
//----------------------------------------
template<typename TYPE>class AOBJ : public TYPE {
public:
	AOBJ( class ACTOR_X* a, const class ATARIO* o, opal::COLOR c = opal::RED ) : actor{a}, atari{o}, color{c} {}

private:
	const class ACTOR_X* const	actor;
	const class ATARIO* const	atari;
	opal::COLOR					color;

public:
	void Init( const char* p = nullptr ) override {

		TYPE::Init( p );
		TYPE::SetDisp( false );
		TYPE::SetColor( color );
		TYPE::Parent( actor );
	}

private:
	void ObjFunc( void ) override;
};

// End Of File
