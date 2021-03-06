#pragma once
//========================================
// mapper.hpp
//========================================
#include "rect2.hpp"
#include "surface.hpp"

//----------------------------------------
// MAPPER
//----------------------------------------
class MAPPER : public RECT2 {
public:
	explicit MAPPER( UINT = 10 );
	virtual ~MAPPER();

private:
	CANVAS			canvas;
	opal::VECTOR2	position;
	opal::SSIZE		size;

public:
	virtual void Init( const char* = nullptr ) override;
	virtual void Free( void ) override;

public:
	virtual void Canvas( const opal::VECTOR2&, const opal::SSIZE& );
	virtual void Canvas( const opal::VECTOR2& );
	virtual void Canvas( const opal::SSIZE&   );

public:
	virtual void Mapping( UINT, UINT, UINT, UINT, opal::COLOR = opal::BLANK );

private:
	virtual void DrawMain( void ) override;

public:
	static auto FloorRect(  UINT, UINT,            float )->std::shared_ptr<opal::SRECTF>;
	static auto WallRect(   UINT, UINT, opal::DIX, float, UINT, float )->std::shared_ptr<opal::SRECTF>;
	static auto CornerRect( UINT, UINT, UINT,      float, UINT, float )->std::shared_ptr<opal::SRECTF>;
};

// End Of File
