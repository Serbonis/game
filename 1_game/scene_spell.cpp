//========================================
// scene_spell.cpp
//========================================
#include "scene_spell.hpp"
#include "scene_game.hpp"

#include "spell_x.hpp"
#include "spell_r.hpp"

//----------------------------------------
// SCENE_SPELL
//----------------------------------------
using namespace opal;

//----------------------------------------
//
//----------------------------------------
void SCENE_SPELL::Init( const char* p ){

	RESOURCE::SPELL::SysInit();

	WORKL::Init( p );

	spell.clear();
}

void SCENE_SPELL::Free( void ){

	spell.clear();

	WORKL::Free();

	RESOURCE::SPELL::SysFree();
}

void SCENE_SPELL::ObjFunc( void ){

	for ( auto& [p,m] : spell.Update() ) {
		( void )p;
		( void )m;
	}
}

//----------------------------------------
//
//----------------------------------------
auto SCENE_SPELL::Generate( SPELL_KIND k )->std::shared_ptr<SPELL_X>{

	if ( const auto p = Make( k ) ) {
		spell[p] = nullptr;
		p->Open();
		p->SetID( Name( k ) );
		p->SetTexture( RESOURCE::SPELL::Texture( p->Kind() ) );
		Game::AtariRegister( "P_SHOT", p );
		return p;
	}
	return nullptr;
}

auto SCENE_SPELL::Generate( const SPELL_DATA& d )->std::shared_ptr<SPELL_X>{

	if ( const auto p = Generate( d.kind ) ) {
		p->SetPosition( d.posx, d.posy, d.height );
		p->SetDirection( d.direction );
		p->SetPower( d.power );
		p->SetSpeed( d.speed );
		return p;
	}
	return nullptr;
}

void SCENE_SPELL::Destroy( std::shared_ptr<SPELL_X> p ){

	if ( p ) {
		p->Close();
		spell.erase( p );
	}
}

void SCENE_SPELL::Destroy( void ){

	for ( auto& [p,s] : spell() ) {
		p->Close();
	}
	spell.clear();
}

//----------------------------------------
//----------------------------------------
#include "spell/fireball.hpp"

auto SCENE_SPELL::Make( SPELL_KIND k )->std::shared_ptr<SPELL_X>{

	switch ( k ) {
	default: break;
	case SPELL_KIND::FireBall : return std::make_shared<SPELL_FIREBALL>( k );
	}
	return nullptr;
}

//----------------------------------------
//----------------------------------------
auto SCENE_SPELL::Name( SPELL_KIND k )->std::string{

	return DATA_SPELL::SpellName( k );
}

// End Of File
