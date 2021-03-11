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
  ���[�_�[
  �~�j�}�b�v
  �O���b�h�̎��E����̃N���b�v
  ���C�g(�t�H�O?)
  �Ǔ����蔻��
  �������蔻��
  �GAI
  �e�L�X�g�E�C���h�E
*/
