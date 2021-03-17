#pragma once
//========================================
// layout.hpp
//========================================
#include "opal.hpp"

//----------------------------------------
// LAYOUT
//----------------------------------------
//----------------------------------------
// game
//----------------------------------------
namespace LAYOUT {
	extern const float	FRAME_SIZE_W;
	extern const float	FRAME_SIZE_H;
	extern const float	FRAME_MASK_W;
	extern const float	FRAME_MASK_H;

	extern const float	FRAME_VIEWPORT_X;
	extern const float	FRAME_VIEWPORT_Y;
	extern const float	FRAME_VIEWPORT_W;
	extern const float	FRAME_VIEWPORT_H;

	extern const float	FRAME_SCISSOR_X;
	extern const float	FRAME_SCISSOR_Y;
	extern const float	FRAME_SCISSOR_W;
	extern const float	FRAME_SCISSOR_H;
}

namespace LAYOUT {
	extern const float	FRAME_MINIMAP_X;
	extern const float	FRAME_MINIMAP_Y;
	extern const float	FRAME_MINIMAP_W;
	extern const float	FRAME_MINIMAP_H;

	extern const std::vector<UINT>	FRAME_MINIMAP_WAKU_COLOR;
	extern const std::vector<UINT>	FRAME_MINIMAP_FLOOR_COLOR;
	extern const std::vector<UINT>	FRAME_MINIMAP_WALL_COLOR;
}

namespace LAYOUT {
	extern const float	FRAME_RADAR_X;
	extern const float	FRAME_RADAR_Y;
	extern const float	FRAME_RADAR_W;
	extern const float	FRAME_RADAR_H;

	extern const std::vector<UINT>	FRAME_RADAR_WAKU_COLOR;
	extern const std::vector<UINT>	FRAME_RADAR_ARROW_COLOR;
	extern const std::vector<UINT>	FRAME_RADAR_FLOOR_COLOR;
	extern const std::vector<UINT>	FRAME_RADAR_WALL_COLOR;
}

namespace LAYOUT {
	extern const float	FRAME_STATUS_X;
	extern const float	FRAME_STATUS_Y;
	extern const float	FRAME_STATUS_W;
	extern const float	FRAME_STATUS_H;

	extern const std::vector<UINT>	FRAME_STATUS_BACK_COLOR;
}

// End Of File
