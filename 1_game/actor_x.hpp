#pragma once
//========================================
// actor_x.hpp
//========================================
#include "actor.hpp"
#include "actor_m.hpp"
#include "actor_c.hpp"
#include "actor_a.hpp"

#include "atari.hpp"

//----------------------------------------
// ACTOR_X
//----------------------------------------
class ACTOR_X :
	public ACTOR,
	public ACTOR_M,
	public ATARIC
{
public:
	explicit ACTOR_X( void* = nullptr );
	virtual ~ACTOR_X() = default;

public:
	virtual void Init( const char* = nullptr ) override;
	virtual void Free( void ) override;
};

//----------------------------------------
// atari
//----------------------------------------
template<typename V, typename A>void AtariBody( A* a, float s, float h, opal::COLOR c = opal::RED ){

	a->ATARIC::SetAtariFlag( true );
	a->ATARIC::SetCollision<COLLISION_3D::CYLINDER>( "BODY", COLLISION_3D::CYLINDER{s,h}, a->MatrixWorld() );
	a->ATARIC::SetAtariFlag( "BODY", true );

	a->template GetView<V>()->Aobject( a, a->ATARIC::AtariSearch( "BODY" ), c );
}

// End Of File
