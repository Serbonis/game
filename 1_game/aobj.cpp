//========================================
// aobj.cpp
//========================================
#include "aobj.hpp"
#include "actor_x.hpp"
#include "aobj_v.hpp"

//----------------------------------------
// AOBJ
//----------------------------------------
using namespace opal;

//----------------------------------------
// AOBJ_CYLINDER
//----------------------------------------
template<>void AOBJ<AOBJ_CYLINDER>::ObjFunc( void ){

	if ( actor->Live() ) {
		SetDisp( true );
		SetHeight( atari->GetShape<COLLISION_3D::CYLINDER>()->Height() );
		SetBottom( atari->GetShape<COLLISION_3D::CYLINDER>()->Length() );
	} else {
		Kill( 0 );
	}
}

//----------------------------------------
// AOBJ_SPHERE
//----------------------------------------
template<>void AOBJ<AOBJ_SPHERE>::ObjFunc( void ){

	if ( actor->Live() ) {
		SetDisp( true );
		SetSize( atari->GetShape<COLLISION_3D::SPHERE>()->Length() );
	} else {
		Kill( 0 );
	}
}

// End Of File
