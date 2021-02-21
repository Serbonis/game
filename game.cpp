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

#if OPAL_DEBUG
static bool	debug_flag;
#endif

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

#if OPAL_DEBUG
	debug_flag = false;
#endif
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
#if OPAL_DEBUG
#include "controll.hpp"
#endif
void GAME::SysExec( void ){

	// �V�[���f�o�b�O
#if OPAL_DEBUG
	if ( CONTROLL::DebugScene() ) {
		FLAG_CTRL( debug_flag, FLAG_FLIP );
	}

	if ( debug_flag ) {
		scene->Debug();
	}
#endif
}

// End Of File
