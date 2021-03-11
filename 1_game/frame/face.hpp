#pragma once
//----------------------------------------
// face.hpp
//----------------------------------------
#include "drawx.hpp"

//----------------------------------------
// FACE
//----------------------------------------
class FACE :
	public opal::DRAWL
{
private:
	std::shared_ptr<class FACE_VIEW>	face;

public:
	virtual void Init( const char* = nullptr ) override;
	virtual void Free( void ) override;

public:
	virtual void Size( float, float );

public:
	virtual void Texture( const class TEXTURE* );

public:
	virtual void ColorWaku( UINT );
	virtual void ColorBack( UINT );
};

// End Of File
