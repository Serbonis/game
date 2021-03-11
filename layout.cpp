//========================================
// layout.cpp
//========================================
#include "layout.hpp"

//----------------------------------------
// LAYOUT
//----------------------------------------
using namespace opal;

//----------------------------------------
// game
//----------------------------------------
//----------------------------------------
//----------------------------------------
namespace LAYOUT {
	const float	FRAME_SIZE_W		= 1600.f;
	const float	FRAME_SIZE_H		= 1200.f;
	const float	FRAME_MASK_W		= 200.f;
	const float	FRAME_MASK_H		= 400.f;

	const float	FRAME_VIEWPORT_X	= 0 - FRAME_MASK_W;
	const float	FRAME_VIEWPORT_Y	= 0;
	const float	FRAME_VIEWPORT_W	= FRAME_SIZE_W;
	const float	FRAME_VIEWPORT_H	= FRAME_SIZE_H;

	const float	FRAME_SCISSOR_X		= 0;
	const float	FRAME_SCISSOR_Y		= FRAME_MASK_H;
	const float	FRAME_SCISSOR_W		= FRAME_SIZE_W - FRAME_MASK_W * 2;
	const float	FRAME_SCISSOR_H		= FRAME_SIZE_H;
}

//----------------------------------------
//----------------------------------------
namespace LAYOUT {
	const float	FRAME_MINIMAP_X		= 0;
	const float	FRAME_MINIMAP_Y		= 0;
	const float	FRAME_MINIMAP_W		= 0;
	const float	FRAME_MINIMAP_H		= 0;
}

//----------------------------------------
//----------------------------------------
namespace LAYOUT {
	static constexpr float	radar_mw	= 16.0f;
	static constexpr float	radar_mh	= 16.0f;

	const float	FRAME_RADAR_X		= FRAME_SCISSOR_W  + radar_mw;
	const float	FRAME_RADAR_Y		= 0                + radar_mh;
	const float	FRAME_RADAR_W		= FRAME_MASK_H     - radar_mw * 2;
	const float	FRAME_RADAR_H		= FRAME_MASK_W * 2 - radar_mh * 2;

	const std::vector<UINT>	FRAME_RADAR_WAKU_COLOR	= { WHITE };
	const std::vector<UINT>	FRAME_RADAR_ARROW_COLOR	= { GREEN, YELLOW, RED };
	const std::vector<UINT>	FRAME_RADAR_FLOOR_COLOR	= { WHITE, GRAY };
	const std::vector<UINT>	FRAME_RADAR_WALL_COLOR	= { MAGENTA };
}

//----------------------------------------
//----------------------------------------
namespace LAYOUT {
	const float	FRAME_STATUS_X	= FRAME_SCISSOR_W;
	const float	FRAME_STATUS_Y	= FRAME_MASK_H;
	const float	FRAME_STATUS_W	= FRAME_MASK_W * 2;
	const float	FRAME_STATUS_H	= 0; // ‰Â•Ï’·

	const std::vector<UINT>	FRAME_STATUS_BACK_COLOR	= { BLUE, BLACK };
}

// End Of File
