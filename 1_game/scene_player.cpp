//========================================
// scene_player.cpp
//========================================
#include "scene_player.hpp"
#include "scene_game.hpp"

#include "player_x.hpp"
#include "player_r.hpp"

//----------------------------------------
// SCENE_PLAYER
//----------------------------------------
using namespace opal;

//----------------------------------------
//
//----------------------------------------
void SCENE_PLAYER::Init( const char* p ){

	RESOURCE::PLAYER::SysInit();

	WORKL::Init( p );
}

void SCENE_PLAYER::Free( void ){

	Destroy();

	WORKL::Free();

	RESOURCE::PLAYER::SysFree();
}

void SCENE_PLAYER::ObjFunc( void ){}

//----------------------------------------
//----------------------------------------
auto SCENE_PLAYER::Generate( UINT n, PLAYER_KIND k )->std::shared_ptr<PLAYER_X>{

	if ( const auto p = PRIMS::MakeSharedPrim( player[n] ) ) {
		p->SetTexture( RESOURCE::PLAYER::TextureBody() );

		p->SetPlayerParam( DATA_PLAYER::PlayerParam( k ) );

		p->SetSpellSpeed( DATA_PLAYER::PLAYER_SPELL_SPEED );
		p->SetSpellPower( DATA_PLAYER::PLAYER_SPELL_POWER );
		p->SetSpellPivot( DATA_PLAYER::PLAYER_SPELL_PIVOT );

		Game::AtariRegister( "PLAYER", p );

		return p;
	}
	return nullptr;
}

void SCENE_PLAYER::Destroy( UINT n ){

	if ( mapped( player, n ) ) {
		maperase( player, n );
	}
}

void SCENE_PLAYER::Destroy( void ){

	mapclear( player );
}

//----------------------------------------
//----------------------------------------
auto SCENE_PLAYER::GetConnect( void ) const->std::weak_ptr<const ACTOR_X>{ return GetConnect( 0 );	}
auto SCENE_PLAYER::GetConnect( UINT n ) const->std::weak_ptr<const ACTOR_X>{

	if ( const auto p = mapped( player, n ) ) {
		return p;
	}
	return {};
}

//----------------------------------------
//----------------------------------------
void SCENE_PLAYER::SetName( const std::string& s ){ SetName( 0, s );	}
void SCENE_PLAYER::SetName( void ){ SetName( 0 );		}
auto SCENE_PLAYER::GetName( void ) const->std::string{ return GetName( 0 ); }

void SCENE_PLAYER::SetName( UINT n, const std::string& s ){

	if ( const auto p = mapped( player, n ) ) {
		p->SetName( s );
	}
}

void SCENE_PLAYER::SetName( UINT n ){

	if ( const auto p = mapped( player, n ) ) {
		p->SetName();
	}
}

auto SCENE_PLAYER::GetName( UINT n ) const->std::string{

	if ( const auto p = mapped( player, n ) ) {
		return p->GetName();
	}
	return "";
}

//----------------------------------------
//
//----------------------------------------
void SCENE_PLAYER::SetPosition(  int x, int y ){ SetPosition( 0, x, y );	}

void SCENE_PLAYER::SetPosition( UINT n, int x, int y ){

	if ( const auto p = mapped( player, n ) ) {
		Game::SetPosition( p, x, y );
		p->SetPosition();
	}
}

//----------------------------------------
//
//----------------------------------------
void SCENE_PLAYER::SetDirection( int d ){ SetDirection( 0, d );	}

void SCENE_PLAYER::SetDirection( UINT n, int d ){

	if ( const auto p = mapped( player, n ) ) {
		Game::SetDirection( p, d );
		p->SetDirection();
	}
}

// End Of File
