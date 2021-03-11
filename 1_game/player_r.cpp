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
		{ PLAYER_KIND::Undef, { "undef.png", "undef_face.png" } },
	};
}

//----------------------------------------
// èâä˙âªÅïå„énññ
//----------------------------------------
namespace RESOURCE::PLAYER {
	void SysInit( void ){

		FILEX::Path( file_path );
		SysInitTexture<PLAYER_KIND>( texture, file_map_texture );
		FILEX::Path( nullptr );
	}

	void SysFree( void ){

		SysFreeTexture<PLAYER_KIND>( texture );
	}
}

//----------------------------------------
// TEXTURE
//----------------------------------------
namespace RESOURCE::PLAYER {
	static auto Texture( PLAYER_KIND k, UINT n )->TEXTURE*{

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

namespace RESOURCE::PLAYER {
	auto TextureBody( void )->TEXTURE*{ return TextureBody( PLAYER_KIND::Undef );	}
	auto TextureFace( void )->TEXTURE*{ return TextureFace( PLAYER_KIND::Undef );	}

	auto TextureBody( PLAYER_KIND k )->TEXTURE*{ return Texture( k, 0 );	}
	auto TextureFace( PLAYER_KIND k )->TEXTURE*{ return Texture( k, 1 );	}
}

// End Of File
