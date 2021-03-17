#pragma once
//========================================
// scene_enemy.hpp
//========================================
#include "enemy_x.hpp"
#include "enemy_k.hpp"

//----------------------------------------
// SCENE ENEMY
//----------------------------------------
class SCENE_ENEMY final : public opal::WORKL{
public:
	void Init( const char* = nullptr ) override;
	void Free( void ) override;

private:
	void ObjFunc( void ) override;

public:
	auto Generate( ENEMY_KIND )->std::shared_ptr<ENEMY_X>;
	void Destroy( std::shared_ptr<ENEMY_X> );
	void Destroy( void );

private:
	static auto Make( ENEMY_KIND )->std::shared_ptr<ENEMY_X>;
	static auto Name( ENEMY_KIND )->std::string;

public:
	void ObjPosition(  std::shared_ptr<ENEMY_X>, int, int, opal::DIM = opal::DIM_0 );
	void ObjDirection( std::shared_ptr<ENEMY_X>, int  );

public:
	void SetStatus( std::shared_ptr<ENEMY_X>, UINT );

private:
	ACTOR_MAPPER<ENEMY_X>	enemy;
};

// End Of File
