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

private:
	virtual void update( void ) final;

protected:
	virtual bool atari_filter( const std::string&, const ATARIC* );

public:
	virtual void SetPosition( float, float, float );
	virtual void SetPosition( float, float );
	virtual void SetPosition( void );
	virtual void SetDirection( float );
	virtual void SetDirection( void  );

	virtual auto GetPosition(  void ) const->std::pair<int,int>;
	virtual auto GetDirection( void ) const->int;

public:
	virtual void SetOffset( float, float, float );
	virtual void SetOffset( float, float );
	virtual void SetOffset( float );
	virtual auto GetOffset( void ) const->opal::DVECTOR;
};

//----------------------------------------
// atari
//----------------------------------------
template<typename V, typename A>void AtariBody( A* a, float s, float h, opal::COLOR c = opal::RED ){

	a->ATARIC::SetAtariFlag( true );
	a->ATARIC::SetCollision<COLLISION_3D::CYLINDER>( "BODY", COLLISION_3D::CYLINDER{s,h}, a->MatrixWorld() );
	a->ATARIC::SetAtariFlag( "BODY", true );

	a->template GetView<V>()->AobjCylinder( a, a->ATARIC::AtariSearch( "BODY" ), c );
}

template<typename V, typename A>void AtariBall( A* a, float s, opal::COLOR c = opal::RED ){

	a->ATARIC::SetAtariFlag( true );
	a->ATARIC::SetCollision<COLLISION_3D::SPHERE>( "BODY", COLLISION_3D::SPHERE{s}, a->MatrixWorld() );
	a->ATARIC::SetAtariFlag( "BODY", true );

	a->template GetView<V>()->AobjSphere( a, a->ATARIC::AtariSearch( "BODY" ), c );
}

// End Of File
