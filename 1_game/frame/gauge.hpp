#pragma once
//----------------------------------------
// gauge.hpp
//----------------------------------------
#include "drawx.hpp"

//----------------------------------------
// GAUGE
//----------------------------------------
class GAUGE :
	public opal::DRAWL,
	public opal::CSIZE2F
{
public:
	enum class STYLE {
		HORIZONTAL,
		VERTICAL
	};

private:
	STYLE								style{STYLE::HORIZONTAL};
	std::shared_ptr<class GAUGE_VIEW>	gauge;

private:
	float	val;
	float	max;

public:
	virtual void Init( const char* = nullptr ) override;
	virtual void Free( void ) override;

public:
	virtual void SetStyle( STYLE );
	virtual auto GetStyle( void ) const->STYLE;

public:
	virtual void SetSize_( float, float ) override;

public:
	virtual void SetVal( float, bool = false );
	virtual void SetVal( void );
	virtual void SetMax( float );
	virtual auto GetVal( void ) const->float;
	virtual auto GetMax( void ) const->float;

public:
	virtual void SetColorBar( UINT );
	virtual void SetColorBar( UINT, UINT );
	virtual void SetColorBar( UINT, UINT, UINT, UINT );
	virtual void SetColorBack( UINT );
	virtual void SetColorBack( UINT, UINT );
	virtual void SetColorBack( UINT, UINT, UINT, UINT );
	virtual void SetColorWaku( UINT );
};

// End Of File
