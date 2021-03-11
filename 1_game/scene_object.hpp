#pragma once
//========================================
// scene_object.hpp
//========================================
#include "scene_player.hpp"
#include "scene_enemy.hpp"
#include "scene_spell.hpp"
#include "scene_grid.hpp"
#include "scene_frame.hpp"

//----------------------------------------
// SCENE OBJECT
//----------------------------------------
struct MAP_DATA;
class SPELL_DATA;

class SCENE_OBJECT final : public opal::WORKL{
public:
	std::shared_ptr<SCENE_PLAYER>	player;
	std::shared_ptr<SCENE_ENEMY>	enemy;
	std::shared_ptr<SCENE_SPELL>	spell;
	std::shared_ptr<SCENE_GRID>		grid;

public:
	void Init( const char* = nullptr ) override;
	void Free( void ) override;

private:
	void ObjFunc( void ) override;

public:
	void GenerateMap( const MAP_DATA* );
	void DestroyMap( void );

private:
	void layout_grid(   const MAP_DATA* );
	void layout_player( const MAP_DATA* );
	void layout_enemy(  const MAP_DATA* );
	void layout_item(   const MAP_DATA* );

public:
	bool GenerateSpell( const SPELL_DATA& );
};

// End Of File
