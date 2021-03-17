#pragma once
//========================================
// scene_player.hpp
//========================================
#include "player_x.hpp"
#include "player_k.hpp"

//----------------------------------------
// SCENE PLAYER
//----------------------------------------
class ACTOR_X;
class SCENE_PLAYER final : public opal::WORKL{
public:
	void Init( const char* = nullptr ) override;
	void Free( void ) override;

private:
	void ObjFunc( void ) override;

private:
	std::map<UINT,std::shared_ptr<class PLAYER_X>>	player;

public:
	auto GetConnect( UINT ) const->std::weak_ptr<const ACTOR_X>;
	auto GetConnect( void ) const->std::weak_ptr<const ACTOR_X>;

public:
	auto Generate( UINT, PLAYER_KIND = PLAYER_KIND::Undef )->std::shared_ptr<PLAYER_X>;
	void Destroy( UINT );
	void Destroy( void );

public:
	void SetName( UINT, const std::string& );
	void SetName( UINT );
	auto GetName( UINT ) const->std::string;

	void SetName( const std::string& );
	void SetName( void );
	auto GetName( void ) const->std::string;

public:
	void SetPosition( UINT, int, int, opal::DIM = opal::DIM_0 );
	void SetPosition( int, int, opal::DIM = opal::DIM_0 );

	void SetDirection( UINT, int );
	void SetDirection( int );

	auto GetPosition( UINT ) const->std::pair<int,int>;
	auto GetPosition( void ) const->std::pair<int,int>;

	auto GetDirection( UINT ) const->int;
	auto GetDirection( void ) const->int;

public:
	auto Rotation( UINT ) const->float;
	auto Rotation( void ) const->float;
};

// End Of File
