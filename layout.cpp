//========================================
// layout.cpp
//========================================
#include "layout.hpp"

//----------------------------------------
// LAYOUT
//----------------------------------------
//----------------------------------------
// game
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

	const float	FRAME_MINIMAP_X		= 0;
	const float	FRAME_MINIMAP_Y		= 0;
	const float	FRAME_MINIMAP_W		= 0;
	const float	FRAME_MINIMAP_H		= 0;

	const float	FRAME_STATUS_MARGIN_W	= 16.f;
	const float	FRAME_STATUS_MARGIN_H	= 16.f;
	const float	FRAME_STATUS_OFFSET_X	= FRAME_STATUS_MARGIN_W;
	const float	FRAME_STATUS_OFFSET_Y	= 16.f;

	const float	FRAME_STATUS_X		= FRAME_SCISSOR_W;
	const float	FRAME_STATUS_Y		= FRAME_MASK_H;
	const float	FRAME_STATUS_W		= FRAME_MASK_W * 2 - FRAME_STATUS_MARGIN_W * 2;
	const float	FRAME_STATUS_H		= 96.f;

	const float	FRAME_STATUS_BACK_W	= FRAME_STATUS_W;
	const float	FRAME_STATUS_BACK_H	= FRAME_STATUS_H;
	const float	FRAME_STATUS_FACE_X = 4;
	const float	FRAME_STATUS_FACE_Y	= 4;
	const float	FRAME_STATUS_FACE_H	= FRAME_STATUS_BACK_H - FRAME_STATUS_FACE_Y * 2;
	const float	FRAME_STATUS_FACE_W	= FRAME_STATUS_FACE_H;
	const float	FRAME_STATUS_NAME_X = FRAME_STATUS_FACE_X + FRAME_STATUS_FACE_W + 4;
	const float	FRAME_STATUS_NAME_Y	= FRAME_STATUS_FACE_Y;
}

// End Of File
