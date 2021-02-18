#pragma once
//========================================
// player_v.hpp
//========================================
#include "actor_v.hpp"

#include "rect3.hpp"
#include "texture.hpp"

//----------------------------------------
// PLAYER V
//----------------------------------------
class PLAYER_V final : public ACTOR_V {
private:
	RECT3	rect3;

public:
	void Init( const char* = nullptr ) override;
	void Free( void ) override;

	void SetTexture( const TEXTURE*, std::shared_ptr<opal::SRECTF> = nullptr );
};

// End Of File
