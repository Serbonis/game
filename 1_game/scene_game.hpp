#pragma once
//========================================
// scene_game.hpp
//========================================
#include "scene_main.hpp"

//----------------------------------------
// SCENE GAME
//----------------------------------------
class SCENE_ATARI;
class SCENE_CAMERA;
class SCENE_PLAYER;
class SCENE_ENEMY;
class SCENE_SPELL;
class SCENE_GRID;

class ATARIS;
class ACTOR_X;

class SPELL_DATA;
struct MAP_DATA;

namespace SCENE_GAME {
	class SCENE_G {
	public:
		SCENE_G();
		~SCENE_G();

	public:
		bool operator()( class SCENE_MANAGER* );

	private:
		void GenerateMap( int = 0 );
		void DestroyMap( void );

	private:
		virtual void layout_grid(   const MAP_DATA* ) final;
		virtual void layout_player( const MAP_DATA* ) final;
		virtual void layout_enemy(  const MAP_DATA* ) final;
		virtual void layout_item(   const MAP_DATA* ) final;

	private:
		UINT			step;
		opal::SSIZE2U	size;

	private:
		std::shared_ptr<SCENE_ATARI>	atari;
		std::shared_ptr<SCENE_CAMERA>	camera;
		std::shared_ptr<SCENE_PLAYER>	player;
		std::shared_ptr<SCENE_ENEMY>	enemy;
		std::shared_ptr<SCENE_SPELL>	spell;
		std::shared_ptr<SCENE_GRID>		grid;

	private:
		static constexpr float	GRID_SIZE = 9.6f;

	public:
		static auto GridSize( void )->float;
		static auto MapSize( void )->opal::SSIZE2U;
		static auto MapPoint(  const opal::VECTOR3& )->opal::POINT2I;
		static auto MapVector( const opal::POINT2I&, float = 0.f )->opal::VECTOR3;
		static auto MapPosition( int, int, float = 0.f )->opal::VECTOR3;
		static auto MapDirection( int )->int;

	public:
		static void SetPosition(  std::shared_ptr<opal::OBJECT>, int, int );
		static void SetDirection( std::shared_ptr<opal::OBJECT>, int );

	public:
		static bool GenerateSpell( const SPELL_DATA& );

	public:
		static void AtariRegister( const char*, std::shared_ptr<ACTOR_X> );
		static void AtariRelease(  const char*, std::shared_ptr<ACTOR_X> );
	};
}

class Game final : public SCENE_GAME::SCENE_G {};

// End Of File
