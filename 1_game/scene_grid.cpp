//========================================
// scene_grid.cpp
//========================================
#include "scene_grid.hpp"
#include "scene_game.hpp"

#include "grid_m.hpp"
#include "grid_r.hpp"

//----------------------------------------
// SCENE_GRID
//----------------------------------------
using namespace opal;

//----------------------------------------
//
//----------------------------------------
void SCENE_GRID::Init( const char* p ){

	RESOURCE::GRID::SysInit();

	WORKL::Init( p );

	draw.Open();

	makeshared( grid );

	Generate();
}

void SCENE_GRID::Free( void ){

	Destroy();

	grid = nullptr;

	draw.Close();

	WORKL::Free();

	RESOURCE::GRID::SysFree();
}

void SCENE_GRID::ObjFunc( void ){}

//----------------------------------------
//
//----------------------------------------
void SCENE_GRID::Generate( SSIZE2U s ){

	size = s;

	for ( auto i = 0UL; i < size.h; i++ ) {
		auto&	l = grid->emplace_back();

		for ( auto j = 0UL; j < size.w; j++ ) {
			const auto	g = l.emplace_back( std::make_shared<GRID_M>() );

			g->Open( this );
			g->SetView( &draw );
			g->Parent( this );

			*g = Game::GridSize();
		}
	}
}

void SCENE_GRID::Generate( UINT w, UINT h ){

	Generate( {w,h} );
}

void SCENE_GRID::Destroy( void ){

	for ( auto& l : *grid ) {
		for ( auto& g : l ) {
			g->Close();
		}
		l.clear();
	}
	grid->clear();

	size = {};
}

//----------------------------------------
//
//----------------------------------------
void SCENE_GRID::SetPosition( int x, int y ){

	if ( size( x, y ) ) {
		Game::SetPosition( (*grid)[y][x], x, y );
	}
}

//----------------------------------------
//----------------------------------------
void SCENE_GRID::SetFloor( UINT x, UINT y, GRID_KIND_FLOOR k ){

	if ( size( x, y ) ) {
		(*grid)[y][x]->SetFloor( k );
	}
}

void SCENE_GRID::SetCeil(  UINT x, UINT y, GRID_KIND_CEIL k ){

	if ( size( x, y ) ) {
		(*grid)[y][x]->SetCeil( k );
	}
}

void SCENE_GRID::SetWall(  UINT x, UINT y, DIX d, GRID_KIND_WALL k ){

	if ( size( x, y ) ) {
		(*grid)[y][x]->SetWall( d, k );
	}
}

// End Of File
