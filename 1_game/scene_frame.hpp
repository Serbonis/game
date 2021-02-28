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
class FRAME_STATUS;

class SCENE_FRAME final : public opal::DRAWL {
public:
	void Init( const char* = nullptr ) override;
	void Free( void ) override;

private:
	std::shared_ptr<FRAME_VIEWPORT>	viewport;
	std::shared_ptr<FRAME_SCISSOR>	scissor;
	std::shared_ptr<FRAME_MINIMAP>	minimap;
	std::shared_ptr<FRAME_STATUS>	status;

public:
	void GenerateStatus( UINT );
	void DestroyStatus(  UINT );

private:
	void ObjFunc( void ) override;
};

// End Of File
