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
	template<typename KEY,typename VAL>using RSRC_MAP = std::map<KEY,std::shared_ptr<VAL>>;
	template<typename KEY>using FILE_MAP = std::map<KEY,std::string>;
}

namespace RESOURCE {
	extern void SysInit( void );
	extern void SysFree( void );
}

namespace RESOURCE {
	auto Texture( const std::string& )->TEXTURE*;
};

// End Of File
