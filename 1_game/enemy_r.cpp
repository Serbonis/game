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
		{ ENEMY_KIND::Mummy, { "mummy.png" } },
	};
}

//----------------------------------------
// èâä˙âªÅïå„énññ
//----------------------------------------
namespace RESOURCE::ENEMY {
	void SysInit( void ){

		FILEX::Path( file_path );
		SysInitTexture<ENEMY_KIND>( texture, file_map_texture );
		FILEX::Path( nullptr );
	}

	void SysFree( void ){

		SysFreeTexture<ENEMY_KIND>( texture );
	}
}

//----------------------------------------
// TEXTURE
//----------------------------------------
namespace RESOURCE::ENEMY {
	auto Texture( ENEMY_KIND k, UINT n )->TEXTURE*{

		if ( texture.count( k ) ) {
			return GetTexture( texture, k, n );
		}

		if ( file_map_texture.count( k ) ) {
			FILEX::Path( file_path );
			InitTexture( k, texture, file_map_texture );
			FILEX::Path( nullptr );
			return GetTexture( texture, k, n );
		}

		return nullptr;
	}
}

// End Of File
