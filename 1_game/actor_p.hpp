#pragma once
//========================================
// actor_p.hpp
//========================================
#include "com.hpp"

//----------------------------------------
// VAL-MAX
//----------------------------------------
namespace PARAMETER {
	struct VALMAX {
		VALMAX( int v, int m ) : val{v},max{m}{}
		VALMAX() = default;

		int	val{0};
		int	max{0};
	};
}

//----------------------------------------
// MOVE
//----------------------------------------
namespace PARAMETER {
	struct MOVE {
		MOVE( float s ) : speed{s}{}
		MOVE() = default;

		float	speed{0};
	};
}

//----------------------------------------
// TURN
//----------------------------------------
namespace PARAMETER {
	struct TURN {
		TURN( float s ) : speed{s}{}
		TURN() = default;

		float	speed{0};
	};
}

//----------------------------------------
// ROTATE
//----------------------------------------
namespace PARAMETER {
	struct ROTATE {
		ROTATE( float s ) : speed{s}{}
		ROTATE() = default;

		float	speed{0};
	};
}

//----------------------------------------
// JUMP
//----------------------------------------
namespace PARAMETER {
	struct JUMP {
		JUMP( float s ) : speed{s}{}
		JUMP() = default;

		float	speed{0};
	};
}

//----------------------------------------
// SPELL
//----------------------------------------
namespace PARAMETER {
	struct SPELL {
		SPELL( float s, float p, opal::VECTOR3 v ) :
			speed{s},
			power{p},
			pivot{v}
		{}
		SPELL( float s, float p ) :
			speed{s},
			power{p}
		{}
		SPELL() = default;

		float			speed{0};
		float			power{0};
		opal::VECTOR3	pivot{0,0,0};
	};
}

// End Of File
