//========================================
// resource.cpp
//========================================
#include "resource.hpp"

//----------------------------------------
// RESOURCE
//----------------------------------------
using namespace opal;

//----------------------------------------
// 初期化＆後始末
//----------------------------------------
namespace RESOURCE {
	void SysInit( void ){}
	void SysFree( void ){}
}

//----------------------------------------
// TETXURE
//----------------------------------------
namespace RESOURCE {
	auto Texture( const std::string& s )->TEXTURE*{

		return nullptr;
	}
}

// End Of File
