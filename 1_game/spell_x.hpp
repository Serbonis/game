#pragma once
//========================================
// spell_x.hpp
//========================================
#include "actor_x.hpp"
#include "spell_m.hpp"

//----------------------------------------
// SPELL X
//----------------------------------------
class SPELL_C :
	public ACTOR_C<ACTOR_A_MOVE>
{};

class SPELL_X :
	public ACTOR_X,
	public SPELL_M,
	public SPELL_C
{
protected:	explicit SPELL_X( SPELL_KIND, void* = nullptr );
private:	explicit SPELL_X() = delete;
public:		virtual ~SPELL_X() = default;

public:
	virtual void Init( const char* = nullptr ) override;
	virtual void Free( void ) override;

public:
	virtual void SetTexture( const class TEXTURE*, std::shared_ptr<opal::SRECTF> = nullptr ) = 0;

private:
	virtual void ObjFunc( void ) override;
};

// End Of File
