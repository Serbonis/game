#pragma once
//========================================
// scissor.hpp
//========================================
#include "drawx.hpp"

//----------------------------------------
// FRAME - SCISSOR
//----------------------------------------
struct FRAME_SCISSOR {
	class BEGIN final :
		public opal::DRAWT,
		public opal::CRECTF
	{
	private:
		virtual void DrawMain( void ) override { opal::DRAWX::SetScissor( *this ); }
	}	begin;

	class END final : public opal::DRAWT {
	private:
		virtual void DrawMain( void ) override { opal::DRAWX::SetScissor(); }
	}	end;
};

// End Of File
