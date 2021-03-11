//========================================
// scene_object.cpp
//========================================
#include "scene_object.hpp"

//----------------------------------------
// SCENE OBJECT
//----------------------------------------
using namespace opal;

//----------------------------------------
//----------------------------------------
void SCENE_OBJECT::Init( const char* p ){

	WORKL::Init( p );

	makeshared( player );
	makeshared( enemy  );
	makeshared( spell  );
	makeshared( grid   );

	player->Open( "PLAYER" );
	enemy->Open(  "ENEMY"  );
	spell->Open(  "SPELL"  );
	grid->Open(   "GRID"   );
}

void SCENE_OBJECT::Free( void ){

	player->Close();
	enemy->Close();
	spell->Close();
	grid->Close();

	player	= nullptr;
	enemy	= nullptr;
	spell	= nullptr;
	grid	= nullptr;
}

//----------------------------------------
//----------------------------------------
void SCENE_OBJECT::ObjFunc( void ){}

//----------------------------------------
// マップ生成
//----------------------------------------
#include "map_data.hpp"

void SCENE_OBJECT::GenerateMap( const MAP_DATA* m ){

	layout_grid( m );
	layout_player( m );
	layout_enemy( m );
	layout_item( m );
}

// MAP
void SCENE_OBJECT::layout_grid( const MAP_DATA* m ){

	const auto	[w,h] = m->map.size;
	const auto	[x,y] = m->map.offset;

	grid->Generate( w, h, x, y );

	for ( auto i = 0UL; i < h; i++ ) {
		for ( auto j = 0UL; j < w; j++ ) {
			const auto	g = m->GridData( j, i );

			grid->ObjPosition( j, i );
			grid->SetFloor( j, i, g->f );
			grid->SetCeil(  j, i, g->c );
			for ( auto d = 0UL; d < DIX_MAX; d++ ) {
				grid->SetWall( j, i, ( DIX )d, g->w[d] );
			}
		}
	}
}

// PLAYER
void SCENE_OBJECT::layout_player( const MAP_DATA* m ){

	const auto	[x,y] = m->player.start;
	const auto	d = m->player.direction;

	player->SetPosition( x, y );
	player->SetDirection( d );
}

// ENEMY
void SCENE_OBJECT::layout_enemy( const MAP_DATA* m ){

	const auto	en = m->enemy.number;
	for ( auto i = 0UL; i < en; i++ ) {
		const auto	d = &m->enemy.data[i];
		const auto	e = enemy->Generate( d->kind );
		const auto	[x,y] = d->position;

		enemy->ObjPosition(  e, x, y );
		enemy->ObjDirection( e, d->direction );
		enemy->SetStatus( e, d->stat );
	}
}

// ITEM
void SCENE_OBJECT::layout_item( const MAP_DATA* m ){}

//----------------------------------------
// マップ破棄
//----------------------------------------
void SCENE_OBJECT::DestroyMap( void ){

	grid->Destroy();
	spell->Destroy();
	enemy->Destroy();
}

//----------------------------------------
//----------------------------------------
bool SCENE_OBJECT::GenerateSpell( const SPELL_DATA& d ){

	return spell->Generate( d ) ? true : false;
}

// End Of File
