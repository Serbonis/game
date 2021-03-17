//========================================
// grid_v.hpp
//========================================
#include "rect3.hpp"
#include "texture.hpp"
#include "grid_k.hpp"

//----------------------------------------
// GRID V
//----------------------------------------
class GRID_V : public opal::DRAW3L{
protected:
	RECT3	c;
	RECT3	f;
	RECT3	w[opal::DIX_MAX];

public:
	virtual void Init( const char* = nullptr ) override;
	virtual void Free( void ) override;

public:
	virtual float operator =( float );

public:
	virtual void Floor( GRID_KIND_FLOOR = GRID_KIND_FLOOR::Undef ) final;
	virtual void Ceil(  GRID_KIND_CEIL = GRID_KIND_CEIL::Undef ) final;
	virtual void Wall(  opal::DIX, GRID_KIND_WALL = GRID_KIND_WALL::Undef ) final;
	virtual void Corner( UINT ) final;
};

// End Of File
