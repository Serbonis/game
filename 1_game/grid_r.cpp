//========================================
// grid_r.cpp
//========================================
#include "grid_r.hpp"

//----------------------------------------
// GRID RESOURCE
//----------------------------------------
using namespace opal;

//----------------------------------------
// TEXTURE
//----------------------------------------
namespace {
	const std::string	file_path = "../Data/grid";

	RESOURCE::RSRC_MAP<GRID_KIND_FLOOR,TEXTURE>	texture_f;
	RESOURCE::RSRC_MAP<GRID_KIND_CEIL, TEXTURE>	texture_c;
	RESOURCE::RSRC_MAP<GRID_KIND_WALL, TEXTURE>	texture_w;

	const RESOURCE::FILE_MAP<GRID_KIND_FLOOR>	file_map_texture_f = {
		{ GRID_KIND_FLOOR::Normal, "floor/normal.jpg" },
		{ GRID_KIND_FLOOR::Portal, "floor/portal.png" },
	};

	const RESOURCE::FILE_MAP<GRID_KIND_CEIL>	file_map_texture_c = {
		{ GRID_KIND_CEIL::Normal, "ceil/normal.jpg" },
	};

	const RESOURCE::FILE_MAP<GRID_KIND_WALL>	file_map_texture_w = {
		{ GRID_KIND_WALL::Normal, "wall/normal.png" },
	};
}

//----------------------------------------
// ‰Šú‰»•ŒãŽn––
//----------------------------------------
namespace RESOURCE::GRID {
	void SysInit( void ){

		FILEX::Path( file_path );
		for ( const auto& [k,f] : file_map_texture_f ) { makeshared( texture_f[k] )->Init( f ); }
		for ( const auto& [k,f] : file_map_texture_c ) { makeshared( texture_c[k] )->Init( f ); }
		for ( const auto& [k,f] : file_map_texture_w ) { makeshared( texture_w[k] )->Init( f ); }
		FILEX::Path( nullptr );
	}

	void SysFree( void ){

		for ( const auto& [k,t] : texture_f ) { t->Free(); }
		for ( const auto& [k,t] : texture_c ) { t->Free(); }
		for ( const auto& [k,t] : texture_w ) { t->Free(); }

		texture_f.clear();
		texture_c.clear();
		texture_w.clear();
	}
}

//----------------------------------------
// TEXTURE
//----------------------------------------
namespace RESOURCE::GRID {
	template<typename KIND,typename TEXT,typename FMAP>auto Texture( KIND k, TEXT texture, FMAP& file_map_texture )->TEXTURE*{

		if ( texture.count( k ) ) {
			return texture.at( k ).get();
		}
		if ( file_map_texture.count( k ) ) {
			FILEX::Path( file_path );
			makeshared( texture[k] )->Init( file_map_texture.at( k ) );
			FILEX::Path( nullptr );
			return texture.at( k ).get();
		}

		return nullptr;
	}

	auto Texture( GRID_KIND_FLOOR k )->TEXTURE*{ return Texture( k, texture_f, file_map_texture_f );	}
	auto Texture( GRID_KIND_CEIL  k )->TEXTURE*{ return Texture( k, texture_c, file_map_texture_c );	}
	auto Texture( GRID_KIND_WALL  k )->TEXTURE*{ return Texture( k, texture_w, file_map_texture_w );	}
}

// End Of File
