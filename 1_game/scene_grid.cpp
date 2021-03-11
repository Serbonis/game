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

	size	= {};
	offset	= {};
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
void SCENE_GRID::Generate( UINT w, UINT h, UINT x, UINT y ){

	size	= {w,h};
	offset	= {x,y};

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

void SCENE_GRID::Destroy( void ){

	for ( auto& l : *grid ) {
		for ( auto& g : l ) {
			g->Close();
		}
		l.clear();
	}
	grid->clear();

	size	= {};
	offset	= {};
}


//----------------------------------------
//
//----------------------------------------
auto SCENE_GRID::Size(   void ) const->opal::SSIZE2U{ return size;		}
auto SCENE_GRID::Offset( void ) const->opal::SSIZE2U{ return offset;	}

//----------------------------------------
//
//----------------------------------------
void SCENE_GRID::ObjPosition( int x, int y ){

	if ( size( x, y ) ) {
		Game::ObjPosition( (*grid)[y][x], x, y );
	}
}

//----------------------------------------
//----------------------------------------
auto SCENE_GRID::Grid( UINT x, UINT y ) const->std::shared_ptr<GRID_M>{

	if ( size( x, y ) ) {
		return (*grid)[y][x];
	}
	return nullptr;
}

void SCENE_GRID::SetFloor( UINT x, UINT y, GRID_KIND_FLOOR k ){

	if ( const auto g = Grid( x, y ) ) {
		g->SetFloor( k );
	}
}

void SCENE_GRID::SetCeil(  UINT x, UINT y, GRID_KIND_CEIL k ){

	if ( const auto g = Grid( x, y ) ) {
		g->SetCeil( k );
	}
}

void SCENE_GRID::SetWall(  UINT x, UINT y, DIX d, GRID_KIND_WALL k ){

	if ( const auto g = Grid( x, y ) ) {
		g->SetWall( d, k );
	}
}

auto SCENE_GRID::GetFloor( UINT x, UINT y ) const->GRID_KIND_FLOOR{

	if ( const auto g = Grid( x, y ) ) {
		return g->GetFloor();
	}
	return GRID_KIND_FLOOR::Undef;
}

auto SCENE_GRID::GetCeil(  UINT x, UINT y ) const->GRID_KIND_CEIL{

	if ( const auto g = Grid( x, y ) ) {
		return g->GetCeil();
	}
	return GRID_KIND_CEIL::Undef;
}

auto SCENE_GRID::GetWall(  UINT x, UINT y, DIX d ) const->GRID_KIND_WALL{

	if ( const auto g = Grid( x, y ) ) {
		return g->GetWall( d );
	}
	return GRID_KIND_WALL::Undef;
}

// End Of File
