//========================================
// scene_enemy.cpp
//========================================
#include "scene_enemy.hpp"
#include "scene_game.hpp"

#include "enemy_x.hpp"
#include "enemy_r.hpp"

//----------------------------------------
// SCENE_ENEMY
//----------------------------------------
using namespace opal;

//----------------------------------------
//
//----------------------------------------
void SCENE_ENEMY::Init( const char* p ){

	RESOURCE::ENEMY::SysInit();

	WORKL::Init( p );

	enemy.clear();
}

void SCENE_ENEMY::Free( void ){

	enemy.clear();

	WORKL::Free();

	RESOURCE::ENEMY::SysFree();
}

void SCENE_ENEMY::ObjFunc( void ){

	//for ( auto& [p,m] : enemy.Update() ) { printd( "ENEMY %s\n", p->GetName() ); }
	//printd( "\n" );
}

//----------------------------------------
//
//----------------------------------------
auto SCENE_ENEMY::Generate( ENEMY_KIND k )->std::shared_ptr<ENEMY_X>{

	if ( const auto p = Make( k ) ) {
		enemy[p] = nullptr;
		p->Open();
		p->SetName( Name( k ) );
		p->SetTexture( RESOURCE::ENEMY::Texture( p->Kind() ) );
		Game::AtariRegister( "ENEMY", p );
		return p;
	}
	return nullptr;
}

void SCENE_ENEMY::Destroy( std::shared_ptr<ENEMY_X> p ){

	if ( p ) {
		p->Close();
		enemy.erase( p );
	}
}

void SCENE_ENEMY::Destroy( void ){

	for ( auto& [p,s] : enemy() ) {
		p->Close();
	}
	enemy.clear();
}

//----------------------------------------
//----------------------------------------
#include "enemy/mummy.hpp"

auto SCENE_ENEMY::Make( ENEMY_KIND k )->std::shared_ptr<ENEMY_X>{

	switch ( k ) {
	default: break;
	case ENEMY_KIND::Mummy : return std::make_shared<ENEMY_MUMMY>( k );
	}
	return nullptr;
}

//----------------------------------------
//----------------------------------------
auto SCENE_ENEMY::Name( ENEMY_KIND k )->std::string{

	return DATA_ENEMY::EnemyName( k );
}

//----------------------------------------
//----------------------------------------
void SCENE_ENEMY::SetPosition( std::shared_ptr<ENEMY_X> e, int x, int y ){

	Game::SetPosition( e, x, y );

	e->SetPosition();
}

void SCENE_ENEMY::SetDirection( std::shared_ptr<ENEMY_X> e, int  d ){

	Game::SetDirection( e, d );

	e->SetDirection();
}

void SCENE_ENEMY::SetStatus( std::shared_ptr<ENEMY_X> e, UINT s ){

	e->SetStat( s );
}

// End Of File
