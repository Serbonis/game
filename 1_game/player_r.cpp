//========================================
// player_r.cpp
//========================================
#include "player_r.hpp"

//----------------------------------------
// PLAYER RESOURCE
//----------------------------------------
using namespace opal;

//----------------------------------------
// TEXTURE
//----------------------------------------
namespace {
	const std::string	file_path = "../Data/player";

	RESOURCE::RSRC_MAP<PLAYER_KIND,TEXTURE>	texture;

	const RESOURCE::FILE_MAP<PLAYER_KIND>	file_map_texture = {
		{ PLAYER_KIND::Undef, "undef.png" },
	};
}

//----------------------------------------
// ‰Šú‰»•ŒãŽn––
//----------------------------------------
namespace RESOURCE::PLAYER {
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
namespace RESOURCE::PLAYER {
	auto Texture( void )->TEXTURE*{

		return Texture( PLAYER_KIND::Undef );
	}

	auto Texture( PLAYER_KIND k )->TEXTURE*{

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
