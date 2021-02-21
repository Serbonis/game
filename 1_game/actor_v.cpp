//========================================
// actor_v.cpp
//========================================
#include "actor_v.hpp"
#include "actor_x.hpp"

//----------------------------------------
// ACTOR_V
//----------------------------------------
using namespace opal;

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
#include "aobj.hpp"
#include "aobj_v.hpp"

class ACTOR_AOBJ {};

template<typename TYPE>void AobjShape( std::shared_ptr<ACTOR_AOBJ>& aobj, ACTOR_X* a, const ATARIO* o, COLOR c ){

	class ACTOR_AOBJ_SHAPE : public ACTOR_AOBJ, public AOBJ<TYPE> { using AOBJ<TYPE>::AOBJ; };

	const auto	p = std::shared_ptr<ACTOR_AOBJ_SHAPE>( new ACTOR_AOBJ_SHAPE{a,o,c}, [](auto p){ p->Close(); } );

	p->Open();

	aobj =  p;
}

void ACTOR_V::AobjCylinder( ACTOR_X* a, const ATARIO* o, COLOR c ){ AobjShape<AOBJ_CYLINDER>( aobj, a, o, c );	}
void ACTOR_V::AobjSphere(   ACTOR_X* a, const ATARIO* o, COLOR c ){ AobjShape<AOBJ_SPHERE  >( aobj, a, o, c );	}

// End Of File
