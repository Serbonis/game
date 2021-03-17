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
void SCENE_OBJECT::ObjFunc( void ){

	const auto	[x,y] = player->GetPosition();
	const auto	r = player->Rotation();

	grid->Eliminate( x, y, r );
}

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
	grid->MapName( m->name );

	for ( auto i = 0UL; i < h; i++ ) {
		for ( auto j = 0UL; j < w; j++ ) {
			const auto	g = m->GridData( j, i );

			if ( GRID_KIND_FLOOR_Exist( g->f ) ) {
				grid->ObjPosition( j, i );
				grid->SetFloor( j, i, g->f );
				grid->SetCeil(  j, i, g->c );
				for ( auto d = 0UL; d < DIX_MAX; d++ ) {
					grid->SetWall( j, i, ( DIX )d, g->w[d] );
				}
				grid->SetCorner( j, i );
			}
		}
	}
}

// PLAYER
void SCENE_OBJECT::layout_player( const MAP_DATA* m ){

	const auto	pn = m->player.number;

	for ( auto i = 0UL; i < pn; i++ ) {
		const auto	pd = &m->player.data[i];
		const auto	[x,y] = pd->position;
		const auto	o = pd->offset;
		const auto	d = pd->direction;

		player->SetPosition( i, x, y, o );
		player->SetDirection( i, d );
	}
}

// ENEMY
void SCENE_OBJECT::layout_enemy( const MAP_DATA* m ){

	const auto	en = m->enemy.number;
	for ( auto i = 0UL; i < en; i++ ) {
		const auto	ed = &m->enemy.data[i];
		const auto	e = enemy->Generate( ed->kind );
		const auto	[x,y] = ed->position;
		const auto	o = ed->offset;

		enemy->ObjPosition(  e, x, y, o );
		enemy->ObjDirection( e, ed->direction );
		enemy->SetStatus( e, ed->stat );
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
