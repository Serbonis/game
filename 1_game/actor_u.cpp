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
// �A�b�v�f�[�g
//----------------------------------------
void ACTOR_X::update( void ){

	// �I�u�W�F�N�g�̍��W�Ɖ�]����}�b�v���ł̈ʒu�ƕ������X�V����
	const auto	p = Game::MapPosition( GetTrans() );
	const auto	d = Game::MapDirection( GetRotateY() );

	ACTOR_M::SetPosition( p.x, p.y );
	ACTOR_M::SetDirection( d );
}

// End Of File
