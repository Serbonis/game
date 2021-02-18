//========================================
// enemy_r.cpp
//========================================
#include "enemy_r.hpp"

//----------------------------------------
// ENEMY RESOURCE
//----------------------------------------
using namespace opal;

//----------------------------------------
// TEXTURE
//----------------------------------------
namespace {
	const std::string	file_path = "../Data/enemy";

	RESOURCE::RSRC_MAP<ENEMY_KIND,TEXTURE>	texture;

	const RESOURCE::FILE_MAP<ENEMY_KIND>	file_map_texture = {
		{ ENEMY_KIND::Mummy, "mummy.png" },
	};
}

//----------------------------------------
// ‰Šú‰»•ŒãŽn––
//----------------------------------------
namespace RESOURCE::ENEMY {
	void SysInit( void ){

		FILEX::Path( file_path );
		for ( const auto& [k,f] : file_map_texture ) { makeshared( texture[k] )->Init( f ); }
		FILEX::Path( nullptr );
	}

	void SysFree( void ){

		for ( const auto& [k,t] : texture ) { t->Free(); }

		texture.clear();
	}
}

//----------------------------------------
// TEXTURE
//----------------------------------------
namespace RESOURCE::ENEMY {
	auto Texture( ENEMY_KIND k )->TEXTURE*{

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
}

// End Of File
