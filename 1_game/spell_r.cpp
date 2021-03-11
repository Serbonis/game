//========================================
// spell_r.cpp
//========================================
#include "spell_r.hpp"

//----------------------------------------
// SPELL RESOURCE
//----------------------------------------
using namespace opal;

//----------------------------------------
// TEXTURE
//----------------------------------------
namespace {
	const std::string	file_path = "../Data/spell";

	RESOURCE::RSRC_MAP<SPELL_KIND,TEXTURE>	texture;

	const RESOURCE::FILE_MAP<SPELL_KIND>	file_map_texture = {
		{ SPELL_KIND::FireBall, { "fireball.png" } },
	};
}

//----------------------------------------
// èâä˙âªÅïå„énññ
//----------------------------------------
namespace RESOURCE::SPELL {
	void SysInit( void ){

		FILEX::Path( file_path );
		SysInitTexture<SPELL_KIND>( texture, file_map_texture );
		FILEX::Path( nullptr );
	}

	void SysFree( void ){

		SysFreeTexture<SPELL_KIND>( texture );
	}
}

//----------------------------------------
// TEXTURE
//----------------------------------------
namespace RESOURCE::SPELL {
	auto Texture( SPELL_KIND k, UINT n )->TEXTURE*{

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
