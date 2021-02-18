#pragma once
//========================================
// actor_s.hpp
//========================================
#include "com.hpp"

//----------------------------------------
// ACTOR STAT
//----------------------------------------
struct ACTOR_STAT {
	static constexpr UINT	Undef = 0;
	static constexpr UINT	Awake = 1 << 0;
	static constexpr UINT	Sleep = 1 << 1;
};

// End Of File
