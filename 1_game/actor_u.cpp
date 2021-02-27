//========================================
// actor_x.cpp
//========================================
#include "actor_x.hpp"

#include "scene_game.hpp"

//----------------------------------------
// ACTOR_X
//----------------------------------------
using namespace opal;

//----------------------------------------
// アップデート
//----------------------------------------
void ACTOR_X::update( void ){

	// オブジェクトの座標と回転からマップ内での位置と方向を更新する
	const auto	p = Game::MapPosition( GetTrans() );
	const auto	d = Game::MapDirection( GetRotateY() );

	ACTOR_M::SetPosition( p.x, p.y );
	ACTOR_M::SetDirection( d );
}

// End Of File
