#pragma once
//========================================
// scene_game.hpp
//========================================
#include "scene_main.hpp"

//----------------------------------------
// SCENE GAME
//----------------------------------------
class SCENE_FRAME;
class SCENE_ATARI;
class SCENE_CAMERA;
class SCENE_OBJECT;

class ATARIS;
class ACTOR_X;

class SPELL_DATA;

namespace SCENE_GAME {
	class SCENE_G {
	public:
		SCENE_G();
		~SCENE_G();

	public:
		bool operator()( class SCENE_MANAGER* );

	private:
		UINT			step;

	private:
		UINT			level;
		opal::SSIZE2U	size;

	private:
		std::shared_ptr<SCENE_FRAME>	frame;
		std::shared_ptr<SCENE_ATARI>	atari;
		std::shared_ptr<SCENE_CAMERA>	camera;
		std::shared_ptr<SCENE_OBJECT>	object;

	private:
		static constexpr float	GRID_SIZE = 9.6f;

	public:
		virtual void BeginLevel( int = 0 ) final;
		virtual void EndLevel( void ) final;

	public:
		static auto GridSize( void )->float;
		static auto MapSize( void )->opal::SSIZE2U;

	public:
		static auto Data2Map( int, int, float = 0.f )->opal::VECTOR3;

	public:
		static auto MapVector( const opal::POINT2I&, float = 0.f )->opal::VECTOR3;
		static auto MapOffset( const opal::VECTOR3& )->opal::DVECTOR;
		static auto MapOffset( float, float )->opal::VECTOR2;
		static auto MapOffsetX( float )->float;
		static auto MapOffsetY( float )->float;

	public:
		static auto MapPosition(  const opal::VECTOR3& )->opal::POINT2I;
		static auto MapDirection( float )->int;

	public:
		static void ObjPosition(  std::shared_ptr<opal::OBJECT>, int, int );
		static void ObjDirection( std::shared_ptr<opal::OBJECT>, int );

	public:
		static bool GenerateSpell( const SPELL_DATA& );

	public:
		static void AtariRegister( const char*, std::shared_ptr<ACTOR_X> );
		static void AtariRelease(  const char*, std::shared_ptr<ACTOR_X> );
	};
}

class Game final : public SCENE_GAME::SCENE_G {};

// End Of File
