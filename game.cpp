//========================================
// game.cpp
//========================================
#include "game.hpp"

#include "resource.hpp"

#include "0_title/scene_main.hpp"
#include "1_game/scene_main.hpp"

//----------------------------------------
// GAME
//----------------------------------------
using namespace opal;

//----------------------------------------
// 初期化
//----------------------------------------
void GAME::SysInit( void ){

	// リソースの初期化
	RESOURCE::SysInit();

	// シーンマネージャー生成
	scene = PRIMS::SharedPrim<SCENE_MANAGER>( this );

	// 各シーンの作成
	scene->SetScene<SCENE_TITLE::SCENE_M>( "TITLE" );
	scene->SetScene<SCENE_GAME ::SCENE_M>( "GAME"  );

	// シーン開始
	//scene->Scene( "TITLE" );
	scene->Scene( "GAME" );
}

//----------------------------------------
// 後始末
//----------------------------------------
void GAME::SysFree( void ){

	// シーンマネージャー破棄
	scene = nullptr;

	// リソースの後始末
	RESOURCE::SysFree();
}

//----------------------------------------
// 実行
//----------------------------------------
void GAME::SysExec( void ){

	// シーンデバッグ
	scene->Debug();
}

// End Of File
