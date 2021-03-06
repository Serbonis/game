#pragma once
//========================================
// fireball_v.hpp
//========================================
#include "spell_v.hpp"

#include "rect3.hpp"
#include "texture.hpp"

//----------------------------------------
// FIREBALL V
//----------------------------------------
class FIREBALL_V final : public SPELL_V {
private:
	RECT3	rect3;

public:
	void Init( const char* = nullptr ) override;
	void Free( void ) override;
	void SetTexture( const TEXTURE*, std::shared_ptr<opal::SRECTF> = nullptr );
};

// End Of File
