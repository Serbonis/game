#pragma once
//========================================
// resource.hpp
//========================================
#include "opal.hpp"

#include "texture.hpp"

//----------------------------------------
// RESOURCE
//----------------------------------------
namespace RESOURCE {
	extern void SysInit( void );
	extern void SysFree( void );
}

namespace RESOURCE {
	auto Texture( const std::string& )->TEXTURE*;
};

//----------------------------------------
//----------------------------------------
namespace RESOURCE {
	template<typename KEY,typename VAL>using RSRC_MAP = std::map<KEY,std::vector<std::shared_ptr<VAL>>>;
	template<typename KEY>using FILE_MAP = std::map<KEY,std::vector<std::string>>;
}

namespace RESOURCE {
	template<typename KIND>auto GetTexture( RSRC_MAP<KIND,TEXTURE>& texture, KIND k, UINT n = 0 )->TEXTURE*{

		return texture.at( k )[n].get();
	}

	template<typename KIND>void InitTexture( KIND k, RSRC_MAP<KIND,TEXTURE>& texture, const FILE_MAP<KIND>& file_map_texture ){

		texture[k] = {};
		for ( const auto& f : file_map_texture.at( k ) ) {
			texture.at( k ).emplace_back( std::make_shared<TEXTURE>() )->Init( f );
		}
	}

	template<typename KIND>void FreeTexture( KIND k, RSRC_MAP<KIND,TEXTURE>& texture ){

		if ( texture.count( k ) ) {
			for ( const auto& t : texture.at( k ) ) {
				t->Free();
			}
			texture.erase( k );
		}
	}

	template<typename KIND>void SysInitTexture( RSRC_MAP<KIND,TEXTURE>& texture, const FILE_MAP<KIND>& file_map_texture ){

		for ( const auto& [k,v] : file_map_texture ) {
			InitTexture( k, texture, file_map_texture );
		}
	}

	template<typename KIND>void SysFreeTexture( RSRC_MAP<KIND,TEXTURE>& texture ){

		for ( const auto& [k,v] : texture ) {
			for ( const auto& t : v ) {
				t->Free();
			}
		}
		texture.clear();
	}
}

// End Of File
