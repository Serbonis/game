//========================================
// actor_x.cpp
//========================================
#include "actor_x.hpp"

#include "scene_game.hpp"

//----------------------------------------
// ACTOR_X
//----------------------------------------
using namespace opal;

//----------------------------------------
// constructor & destructor
//----------------------------------------
ACTOR_X::ACTOR_X( void* p ) :
	ACTOR{p}
{}

//----------------------------------------
// ‰Šú‰»•ŒãŽn––
//----------------------------------------
void ACTOR_X::Init( const char* p ){

	ACTOR::Init( p );
	SetDim3( true );

	ATARIC::AtariInit();
	ATARIC::SetAtariFilter( FILTER_BIND( this, &ACTOR_X::atari_filter ) );

	SetUpdater( "update", [&]{ update(); }	);
}

void ACTOR_X::Free( void ){

	ATARIC::AtariFree();

	ACTOR::Free();
}

bool ACTOR_X::atari_filter( const std::string& s, const ATARIC* c ){

	if ( const auto a = c->GetAtariOwner<ACTOR_X>() ) {
		return GetPosition() == a->GetPosition();
	}
	return false;
}

//----------------------------------------
//----------------------------------------
void ACTOR_X::SetPosition( float x, float z, float h ){

	SetTrans( x, h, z );
}

void ACTOR_X::SetPosition( float x, float z ){

	SetTransX( x );
	SetTransZ( z );
}

void ACTOR_X::SetDirection( float d ){

	SetRotate( d );
}

void ACTOR_X::SetPosition( void ){

	const auto	[x,y,z] = GetTrans();

	SetPosition( x, z, y );
}

auto ACTOR_X::GetPosition( void ) const->std::pair<int,int>{

	return ACTOR_M::GetPosition();
}

void ACTOR_X::SetDirection( void ){

	SetDirection( GetRotate() );
}

auto ACTOR_X::GetDirection( void ) const->int{

	return ACTOR_M::GetDirection();
}

//----------------------------------------
//----------------------------------------
void ACTOR_X::SetOffset( float x, float y, float h ){}
void ACTOR_X::SetOffset( float x, float y ){}
void ACTOR_X::SetOffset( float h ){}

auto ACTOR_X::GetOffset( void ) const->opal::DVECTOR{ return Game::MapOffset( GetTrans() ); }

// End Of File
