//========================================
// mummy.cpp
//========================================
#include "mummy.hpp"
#include "mummy_v.hpp"

//----------------------------------------
// ENEMY MUMMY
//----------------------------------------
using namespace opal;

//----------------------------------------
// constructor & destructor
//----------------------------------------
ENEMY_MUMMY::ENEMY_MUMMY( ENEMY_KIND k, void* g ) :
	ENEMY_X{k,g},
	MUMMY_C{this}
{}

class FSM_MUMMY final : public FSM_FUNCTION{
public:
	FSM_MUMMY(){}
};

//----------------------------------------
//----------------------------------------
void ENEMY_MUMMY::Init( const char* p ){

	ENEMY_X::Init( p );

	SetView<MUMMY_V>();

	ACTOR_A_MOVE::SetAction<FSM_MUMMY>( "fsm", FSM_BIND( this, &ENEMY_MUMMY::fsm_move ) );
	SetUpdater( "MUMMY_C", [&]{ MUMMY_C::Updater( this ); } );

	AtariBody<MUMMY_V>( this, 2, 2 );
}

void ENEMY_MUMMY::Free( void ){

	SetView();

	ENEMY_X::Free();
}

//----------------------------------------
//----------------------------------------
void ENEMY_MUMMY::SetTexture( const class TEXTURE* t, std::shared_ptr<opal::SRECTF> r ){

	GetView<MUMMY_V>()->SetTexture( t, r );
}

//----------------------------------------
//----------------------------------------
auto ENEMY_MUMMY::fsm_move( FSM_ARGP )->FSM_RETV{

	return FSM_CONTINUE();
}

//----------------------------------------
//----------------------------------------
auto ENEMY_MUMMY::fsm_past( FSM_ARGP )->FSM_RETV{

	return FSM_CONTINUE();
}

// End Of File
