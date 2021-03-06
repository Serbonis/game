//========================================
// scene_game.cpp
//========================================
#include "scene_game.hpp"

//----------------------------------------
// SCENE GAME
//----------------------------------------
using namespace opal;
using namespace SCENE_TITLE;

//----------------------------------------
// 初期化
//----------------------------------------
SCENE_G::SCENE_G(){
	title.Open( "TITLE" );
}

//----------------------------------------
// 後始末
//----------------------------------------
SCENE_G::~SCENE_G(){
	title.Close();
}

//----------------------------------------
// 実行
//----------------------------------------
bool SCENE_G::operator()( SCENE_MANAGER* ){

	return PADX::KeyTrig( KEY_SPACE );
}

// End Of File
