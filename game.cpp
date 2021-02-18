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
// ������
//----------------------------------------
void GAME::SysInit( void ){

	// ���\�[�X�̏�����
	RESOURCE::SysInit();

	// �V�[���}�l�[�W���[����
	scene = PRIMS::SharedPrim<SCENE_MANAGER>( this );

	// �e�V�[���̍쐬
	scene->SetScene<SCENE_TITLE::SCENE_M>( "TITLE" );
	scene->SetScene<SCENE_GAME ::SCENE_M>( "GAME"  );

	// �V�[���J�n
	//scene->Scene( "TITLE" );
	scene->Scene( "GAME" );
}

//----------------------------------------
// ��n��
//----------------------------------------
void GAME::SysFree( void ){

	// �V�[���}�l�[�W���[�j��
	scene = nullptr;

	// ���\�[�X�̌�n��
	RESOURCE::SysFree();
}

//----------------------------------------
// ���s
//----------------------------------------
void GAME::SysExec( void ){

	// �V�[���f�o�b�O
	scene->Debug();
}

// End Of File
