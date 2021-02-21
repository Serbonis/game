#pragma once
//========================================
// aobj_v.hpp
//========================================
#include "line3.hpp"
#include "maru3.hpp"

//----------------------------------------
// AOBJ_CYLINDER
//----------------------------------------
class AOBJ_CYLINDER : public opal::DRAWL {
private:
	LINE3	height;
	MARU3	bottom;

public:
	virtual void Init( const char* = nullptr ) override;
	virtual void Free( void ) override;

public:
	virtual void SetColor( opal::COLOR );

public:
	virtual void SetHeight( float );
	virtual void SetBottom( float );
};

//----------------------------------------
// AOBJ_SPHERE
//----------------------------------------
class AOBJ_SPHERE : public opal::DRAWL {
private:
	MARU3	axis[3];

public:
	virtual void Init( const char* = nullptr ) override;
	virtual void Free( void ) override;

public:
	virtual void SetColor( opal::COLOR );

public:
	virtual void SetSize( float );
};

// End Of File
