//========================================
// grid_d.cpp
//========================================
#include "grid_d.hpp"

//----------------------------------------
// DATA - GRID
//----------------------------------------
using namespace opal;

//----------------------------------------
// constructor & destructor
//----------------------------------------
namespace {
	extern const std::unordered_map<std::string,GRID_KIND_FLOOR>	grid_kind_floor;
	extern const std::unordered_map<std::string,GRID_KIND_CEIL >	grid_kind_ceil;
	extern const std::unordered_map<std::string,GRID_KIND_WALL >	grid_kind_wall;
}

namespace DATA_GRID {
	auto GridKindFloor( void )->GRID_KIND_FLOOR{ return GRID_KIND_FLOOR::Undef;	}
	auto GridKindCeil(  void )->GRID_KIND_CEIL{  return GRID_KIND_CEIL::Undef;	}
	auto GridKindWall(  void )->GRID_KIND_WALL{  return GRID_KIND_WALL::Undef;	}

	template<typename KIND>auto GridKind( const std::string& s, const std::unordered_map<std::string,KIND>& grid_kind )->KIND{

		return grid_kind.count( s ) ? grid_kind.at( s ) : KIND::Undef;
	}
	auto GridKindFloor( const std::string& s )->GRID_KIND_FLOOR{ return GridKind( s, grid_kind_floor );	}
	auto GridKindCeil(  const std::string& s )->GRID_KIND_CEIL{  return GridKind( s, grid_kind_ceil  );	}
	auto GridKindWall(  const std::string& s )->GRID_KIND_WALL{  return GridKind( s, grid_kind_wall  );	}
}

namespace {
	DECLTYPE( grid_kind_floor ) = {
			{ "Å†", GRID_KIND_FLOOR::Normal },
			{ "Åù", GRID_KIND_FLOOR::Portal },
			{ "Å~", GRID_KIND_FLOOR::Block	},
	};
	DECLTYPE( grid_kind_ceil  ) = {
			{ "Å†", GRID_KIND_CEIL::Normal },
			{ "Åù", GRID_KIND_CEIL::Normal },
	};
	DECLTYPE( grid_kind_wall  ) = {
			{ "Ñ™", GRID_KIND_WALL::Normal },
			{ "Ñ´", GRID_KIND_WALL::Normal },
	};
}

// End Of File
