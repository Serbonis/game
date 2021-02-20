//========================================
// actor_v.cpp
//========================================
#include "actor_v.hpp"
#include "actor_x.hpp"

//----------------------------------------
// ACTOR_V
//----------------------------------------
using namespace opal;

#include "aobj.hpp"
#include "aobj_cylinder.hpp"

class ACTOR_AOBJ : public AOBJ<AOBJ_CYLINDER> {
	using AOBJ::AOBJ;
};

//----------------------------------------
//----------------------------------------
void ACTOR_V::Init( const char* p ){

	ACTOR_VIEW::Init( p );

	shadow	= nullptr;
	aobj 	= nullptr;
}

void ACTOR_V::Free( void ){

	shadow	= nullptr;
	aobj 	= nullptr;

	ACTOR_VIEW::Free();
}

//----------------------------------------
//----------------------------------------
void ACTOR_V::Aobject( class ACTOR_X* a, const class ATARIO* o, opal::COLOR c ){

	( aobj = std::shared_ptr<ACTOR_AOBJ>( new ACTOR_AOBJ{a,o,c}, [](auto p){ p->Close(); } ) )->Open();
}

// End Of File
