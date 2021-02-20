//========================================
// aobj.cpp
//========================================
#include "aobj.hpp"
#include "actor_x.hpp"

//----------------------------------------
// AOBJ
//----------------------------------------
using namespace opal;

//----------------------------------------
// AOBJ_CYLINDER
//----------------------------------------
#include "aobj_cylinder.hpp"

template<>void AOBJ<AOBJ_CYLINDER>::ObjFunc( void ){

	if ( actor->Live() ) {
		SetDisp( true );
		SetHeight( atari->GetShape<COLLISION_3D::CYLINDER>()->Height() );
		SetBottom( atari->GetShape<COLLISION_3D::CYLINDER>()->Length() );
	} else {
		Kill( 0 );
	}
}

// End Of File
