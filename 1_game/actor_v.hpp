#pragma once
//========================================
// actor_x.hpp
//========================================
#include "actor.hpp"

//----------------------------------------
// ACTOR_V
//----------------------------------------
class ACTOR_V : public ACTOR_VIEW{
protected:
	std::shared_ptr<class ACTOR_SHADOW>	shadow;

public:
	//virtual void Init( const char* = nullptr ) override;
	//virtual void Free( void ) override;
};

// End Of File
