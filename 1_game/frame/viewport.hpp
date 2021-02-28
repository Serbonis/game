#pragma once
//========================================
// viewport.hpp
//========================================
#include "drawx.hpp"

//----------------------------------------
// FRAME - VIEWPORT
//----------------------------------------
struct FRAME_VIEWPORT {
	class BEGIN final :
		public opal::DRAWT,
		public opal::CRECTF
	{
	private:
		virtual void DrawMain( void ) override { opal::DRAWX::ViewportBegin( *this ); }
	}	begin;

	class END final : public opal::DRAWT {
	private:
		virtual void DrawMain( void ) override { opal::DRAWX::ViewportEnd(); }
	}	end;
};

// End Of File
