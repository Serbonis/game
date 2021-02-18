#pragma once
//========================================
// enemy_x.hpp
//========================================
#include "actor_x.hpp"
#include "enemy_m.hpp"

//----------------------------------------
// ENEMY X
//----------------------------------------
class ENEMY_C :
	public ACTOR_C<ACTOR_A_MOVE>
{
	using ACTOR_C::ACTOR_C;
};

class ENEMY_X :
	public ACTOR_X,
	public ENEMY_M,
	public ENEMY_C
{
protected:	explicit ENEMY_X( ENEMY_KIND, void* = nullptr );
private:	explicit ENEMY_X() = delete;
public:		virtual ~ENEMY_X() = default;
public:
	virtual void Init( const char* = nullptr ) override;
	virtual void Free( void ) override;

public:
	virtual void SetTexture( const class TEXTURE*, std::shared_ptr<opal::SRECTF> = nullptr ) = 0;

private:
	virtual void ObjFunc( void ) override;
};

// End Of File
