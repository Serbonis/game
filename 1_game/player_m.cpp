//========================================
// player_m.cpp
//========================================
#include "player_m.hpp"

#include "scene_game.hpp"

//----------------------------------------
// PLAYER M
//----------------------------------------
using namespace opal;

//----------------------------------------
// constructor & destructor
//----------------------------------------

//----------------------------------------
//----------------------------------------
auto PLAYER_M::Kind( void ) const->PLAYER_KIND{ return kind;	}

//----------------------------------------
//----------------------------------------
#include "spell_k.hpp"
#include "spell_d.hpp"

void PLAYER_M::Spell( SPELL_KIND k, float p, float s, float x, float y, float h, float r ){

	Game::GenerateSpell( SPELL_DATA{k,p,s,x,y,h,r} );
}

// End Of File
