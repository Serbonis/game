#pragma once
//========================================
// enemy_v.hpp
//========================================
#include "actor_v.hpp"

//----------------------------------------
// ENEMY V
//----------------------------------------
class ENEMY_V : public ACTOR_V {
protected:
	class TEXTURE*	towards;
	class TEXTURE*	away;
	class TEXTURE*	right;
	class TEXTURE*	left;
	class TEXTURE*	attack;
	class TEXTURE*	cast;

	//std::string endanim,endmusic,endsound,picstring,soundstring;
	std::string endanim,endsound,picstring,soundstring,footstep;
};

// End Of File
