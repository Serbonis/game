//========================================
// resource.cpp
//========================================
#include "resource.hpp"

//----------------------------------------
// RESOURCE
//----------------------------------------
using namespace opal;

//----------------------------------------
// TEXTURE
//----------------------------------------
#include "texture.hpp"

namespace {
	const std::unordered_map<std::string,std::string>	filename = {};

	std::unordered_map<std::string,std::shared_ptr<TEXTURE>>	common;
}

//----------------------------------------
// èâä˙âªÅïå„énññ
//----------------------------------------
namespace RESOURCE {
	void SysInit( void ){

		FILEX::Path( "../Data" );
		for ( const auto& [k,f] : filename ) {
			common[k] = std::make_shared<TEXTURE>();
			common[k]->Init( f );
		}
	}

	void SysFree( void ){

		for ( const auto& [k,f] : filename ) {
			common[k]->Free();
			common[k] = nullptr;
		}
		common.clear();
	}
}

//----------------------------------------
// TETXURE
//----------------------------------------
namespace RESOURCE {
	auto Texture( const std::string& s )->TEXTURE*{

		if ( common.count( s ) ) {
			return common.at( s ).get();
		}

		return nullptr;
	}
}

// End Of File
