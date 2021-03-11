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
		{ GRID_KIND_FLOOR::Normal, { "floor/normal.jpg" } },
		{ GRID_KIND_FLOOR::Portal, { "floor/portal.png" } },
	};

	const RESOURCE::FILE_MAP<GRID_KIND_CEIL>	file_map_texture_c = {
		{ GRID_KIND_CEIL::Normal, { "ceil/normal.jpg" } } ,
	};

	const RESOURCE::FILE_MAP<GRID_KIND_WALL>	file_map_texture_w = {
		{ GRID_KIND_WALL::Normal, { "wall/normal.png" } } ,
	};
}

//----------------------------------------
// èâä˙âªÅïå„énññ
//----------------------------------------
namespace RESOURCE::GRID {
	void SysInit( void ){

		FILEX::Path( file_path );
		SysInitTexture<GRID_KIND_FLOOR>( texture_f, file_map_texture_f );
		SysInitTexture<GRID_KIND_CEIL >( texture_c, file_map_texture_c );
		SysInitTexture<GRID_KIND_WALL >( texture_w, file_map_texture_w );
		FILEX::Path( nullptr );
	}

	void SysFree( void ){

		SysFreeTexture<GRID_KIND_FLOOR>( texture_f );
		SysFreeTexture<GRID_KIND_CEIL >( texture_c );
		SysFreeTexture<GRID_KIND_WALL >( texture_w );
	}
}

//----------------------------------------
// TEXTURE
//----------------------------------------
namespace RESOURCE::GRID {
	template<typename KIND,typename TEXT,typename FMAP>static auto Texture( KIND k, TEXT& texture, const FMAP& file_map_texture )->TEXTURE*{

		if ( texture.count( k ) ) {
			return GetTexture( texture, k );
		}

		if ( file_map_texture.count( k ) ) {
			FILEX::Path( file_path );
			InitTexture( k, texture, file_map_texture );
			FILEX::Path( nullptr );
			return GetTexture( texture, k );
		}

		return nullptr;
	}

	auto Texture( GRID_KIND_FLOOR k )->TEXTURE*{ return Texture( k, texture_f, file_map_texture_f );	}
	auto Texture( GRID_KIND_CEIL  k )->TEXTURE*{ return Texture( k, texture_c, file_map_texture_c );	}
	auto Texture( GRID_KIND_WALL  k )->TEXTURE*{ return Texture( k, texture_w, file_map_texture_w );	}
}

// End Of File
