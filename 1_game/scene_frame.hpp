#pragma once
//========================================
// scene_frame.hpp
//========================================
#include "drawx.hpp"

//----------------------------------------
// SCENE FRAME
//----------------------------------------
class FRAME_VIEWPORT;
class FRAME_SCISSOR;
class FRAME_MINIMAP;
class FRAME_RADAR;
class FRAME_STATUS;
class ACTOR_X;

class SCENE_FRAME final : public opal::DRAWL {
public:
	void Init( const char* = nullptr ) override;
	void Free( void ) override;

private:
	void ObjFunc( void ) override;

private:
	std::shared_ptr<FRAME_VIEWPORT>	viewport;
	std::shared_ptr<FRAME_SCISSOR>	scissor;
	std::shared_ptr<FRAME_MINIMAP>	minimap;
	std::shared_ptr<FRAME_RADAR>	radar;
	std::shared_ptr<FRAME_STATUS>	status;

private:
	std::map<UINT,std::weak_ptr<const ACTOR_X>>	actor;

public:
	void GenerateStatus( UINT );
	void GenerateStatus( UINT, std::weak_ptr<const ACTOR_X> );
	void DestroyStatus(  UINT );

public:
	void SetConnect( UINT, std::weak_ptr<const ACTOR_X> );
	auto GetConnect( UINT ) const->std::weak_ptr<const ACTOR_X>;

public:
	void StatusName(  UINT, const std::string& );
	void StatusName(  UINT );
	void StatusFace(  UINT, class TEXTURE* = nullptr );
	void StatusValHP( UINT );
	void StatusValHP( UINT, float, bool = true );
	void StatusValMP( UINT, float, bool = true );
	void StatusMaxHP( UINT, float );
	void StatusMaxMP( UINT, float );
};

// End Of File
