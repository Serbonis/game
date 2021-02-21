//========================================
// fireball.cpp
//========================================
#include "fireball.hpp"
#include "fireball_v.hpp"

//----------------------------------------
// SPELL FIREBALL
//----------------------------------------
using namespace opal;

//----------------------------------------
// constructor & destructor
//----------------------------------------
SPELL_FIREBALL::SPELL_FIREBALL( SPELL_KIND k, void* g ) :
	SPELL_X{k,g},
	FIREBALL_C{this}
{}

class FSM_FIREBALL final : public FSM_FUNCTION{
public:
	FSM_FIREBALL( UINT t ){ time = t; }
};

//----------------------------------------
//----------------------------------------
void SPELL_FIREBALL::Init( const char* p ){

	SPELL_X::Init( p );

	SetView<FIREBALL_V>();

	ACTOR_A_MOVE::SetAction<FSM_FIREBALL>( "fsm", FSM_BIND( this, &SPELL_FIREBALL::fsm_move ), SEC( 1 ) );
	SetUpdater( "FIREBALL_C", [&]{ FIREBALL_C::Updater( this ); } );

	AtariBall<FIREBALL_V>( this, 1 );
	ATARIC::SetAtariFuncOn( [&]( auto, auto, auto, auto ){} );

	ATARIC::SetAtariFilter( FILTER_BIND( this, &SPELL_FIREBALL::atari_filter ) );
}

void SPELL_FIREBALL::Free( void ){

	SetView();

	SPELL_X::Free();
}

//----------------------------------------
//----------------------------------------
void SPELL_FIREBALL::SetTexture( const class TEXTURE* t, std::shared_ptr<opal::SRECTF> r ){

	GetView<FIREBALL_V>()->SetTexture( t, r );
}

//----------------------------------------
//----------------------------------------
auto SPELL_FIREBALL::fsm_move( FSM_ARGP a )->FSM_RETV{

	const auto	w = FSM_WORK<FSM_FIREBALL>( a );

	if ( !w->time-- ) {
		Kill( 0 );
		return FSM_END();
	}

	MoveF( GetSpeed() );

	return FSM_CONTINUE();
}

//----------------------------------------
//----------------------------------------
#include "enemy_x.hpp"

bool SPELL_FIREBALL::atari_filter( const std::string& s, const ATARIC* c ){

	if ( s == "ENEMY" ) {
		const auto	p = c->GetAtariOwner<ENEMY_X>();
		printd( "%p\n",  p );
	}

	return true;
}

// End Of File
