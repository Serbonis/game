#pragma once
//========================================
// scene_spell.hpp
//========================================
#include "spell_x.hpp"
#include "spell_k.hpp"
#include "spell_d.hpp"

//----------------------------------------
// SCENE SPELL
//----------------------------------------
class SCENE_SPELL final : public opal::WORKL{
public:
	void Init( const char* = nullptr ) override;
	void Free( void ) override;

private:
	void ObjFunc( void ) override;

public:
	auto Generate( SPELL_KIND )->std::shared_ptr<SPELL_X>;
	auto Generate( const SPELL_DATA& )->std::shared_ptr<SPELL_X>;
	void Destroy( std::shared_ptr<SPELL_X> );
	void Destroy( void );

private:
	static auto Make( SPELL_KIND )->std::shared_ptr<SPELL_X>;
	static auto Name( SPELL_KIND )->std::string;

private:
	ACTOR_MAPPER<SPELL_X>	spell;
};

// End Of File
