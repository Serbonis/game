#pragma once
//========================================
// actor_x.hpp
//========================================
#include "actor.hpp"

//----------------------------------------
// ACTOR_V
//----------------------------------------
class ACTOR_V : public ACTOR_VIEW {
protected:
	std::shared_ptr<class ACTOR_SHADOW>	shadow;
	std::shared_ptr<class ACTOR_AOBJ>	aobj;

public:
	virtual void Init( const char* = nullptr ) override;
	virtual void Free( void ) override;

public:
	virtual void AobjCylinder( class ACTOR_X*, const class ATARIO*, opal::COLOR = opal::RED ) final;
	virtual void AobjSphere(   class ACTOR_X*, const class ATARIO*, opal::COLOR = opal::RED ) final;
};

// End Of File
