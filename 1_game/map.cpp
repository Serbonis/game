//========================================
// map.cpp
//========================================
#include "map.hpp"
#include "grid_d.hpp"
#include "enemy_d.hpp"

//----------------------------------------
// MAP DATA
//----------------------------------------
using namespace opal;

//----------------------------------------
//----------------------------------------
GRID_DATA::GRID_DATA() :
	f{GRID_KIND_FLOOR::Undef},
	c{GRID_KIND_CEIL::Undef},
	w{GRID_KIND_WALL::Undef,GRID_KIND_WALL::Undef,GRID_KIND_WALL::Undef,GRID_KIND_WALL::Undef}
{}

GRID_DATA::GRID_DATA( GRID_KIND_FLOOR f, GRID_KIND_CEIL c, GRID_KIND_WALL wn, GRID_KIND_WALL we, GRID_KIND_WALL ws, GRID_KIND_WALL ww ) :
	f{f},
	c{c},
	w{wn,we,ws,ww}
{}

GRID_DATA::GRID_DATA( GRID_KIND_FLOOR f, GRID_KIND_CEIL c, const std::vector<GRID_KIND_WALL>& w ) :
	f{f},
	c{c},
	w{w[0],w[1],w[2],w[3]}
{}

auto MAP_DATA::GridDataFloor( UINT x, UINT y ) const->std::string{

	if ( const auto [w,h] = map.size; x < w && y < h ) {
		const auto	sx = 2*x+1;
		const auto	sy = 2*y+1;
		const auto	sp = &map.data[sy][2*sx];

		return std::string{ sp[0], sp[1] };
	}
	return "";
}

auto MAP_DATA::GridDataCeil( UINT x, UINT y ) const->std::string{

	if ( const auto [w,h] = map.size; x < w && y < h ) {
		return GridDataFloor( x, y );
	}
	return "";
}
auto MAP_DATA::GridDataWall( UINT x, UINT y, DIX d ) const->std::string{

	if ( const auto [w,h] = map.size; x < w && y < h ) {
		switch ( d ) {
		default: break;
		case DIX_N:
			{
				const auto	sx = 2*x+1;
				const auto	sy = 2*y+1 - 1;
				const auto	sp = &map.data[sy][2*sx];
				return std::string{ sp[0], sp[1] };
			}
		case DIX_E:
			{
				const auto	sx = 2*x+1 + 1;
				const auto	sy = 2*y+1;
				const auto	sp = &map.data[sy][2*sx];
				return std::string{ sp[0], sp[1] };
			}
		case DIX_S:
			{
				const auto	sx = 2*x+1;
				const auto	sy = 2*y+1 + 1;
				const auto	sp = &map.data[sy][2*sx];
				return std::string{ sp[0], sp[1] };
			}
		case DIX_W:
			{
				const auto	sx = 2*x+1 - 1;
				const auto	sy = 2*y+1;
				const auto	sp = &map.data[sy][2*sx];
				return std::string{ sp[0], sp[1] };
			}
		}
	}
	return "";
}

auto MAP_DATA::GridData( UINT x, UINT y ) const->std::shared_ptr<GRID_DATA>{

	if ( const auto [w,h] = map.size; x < w && y < h ) {
		const auto	fk = DATA_GRID::GridKindFloor( GridDataFloor( x, y ) );
		const auto	ck = DATA_GRID::GridKindCeil(  GridDataCeil(  x, y ) );
		const auto	wk = std::vector<GRID_KIND_WALL>{
			DATA_GRID::GridKindWall( GridDataWall( x, y, DIX_N ) ),
			DATA_GRID::GridKindWall( GridDataWall( x, y, DIX_E ) ),
			DATA_GRID::GridKindWall( GridDataWall( x, y, DIX_S ) ),
			DATA_GRID::GridKindWall( GridDataWall( x, y, DIX_W ) ),
		};
		return std::make_shared<GRID_DATA>( fk, ck, wk );
	}
	return nullptr;
}

// End Of File
