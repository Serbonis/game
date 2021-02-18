#pragma once
//========================================
// camera_p.hpp
//========================================
#include "work.hpp"
#include "mover.hpp"

//----------------------------------------
// PLATFORM
//----------------------------------------
class ACTOR_X;
class PLATFORM final : public opal::WORKL{
private:
	const ACTOR_X*	subject;
	opal::POINT2I	point;

	MOVER1	move_x;
	MOVER1	move_z;
	float	time;

public:
	void Init( const char* = nullptr ) override;
	void Free( void ) override;

public:
	auto operator =( const opal::POINT2I& p )->auto{ return point = p;	}

public:
	void SetConnect( const ACTOR_X* );

private:
	void ObjFunc( void ) override;
};

// End Of File
