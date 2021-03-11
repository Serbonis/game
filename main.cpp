//========================================
// main.cpp
//========================================
#include <Opal.hpp>
#include "game.hpp"

using namespace opal;

int main(){

	OPAL::PROJECT( GAME::PROJECT );
	OPAL::BGCOLOR( BLACK );

	return Opal( new GAME );
}

// End Of File

// TODO
/*
  レーダー
  ミニマップ
  グリッドの視界からのクリップ
  ライト(フォグ?)
  壁当たり判定
  床当たり判定
  敵AI
  テキストウインドウ
*/
