#pragma once
//========================================
// mapper_v.hpp
//========================================
#include "com.hpp"

//----------------------------------------
// MAPPER - VIEW
//----------------------------------------
class MAPPER_VIEW_I {
public:
	virtual void Clear( void ) = 0;

public:
	virtual void Floor(  UINT, UINT,            opal::COLOR = opal::BLANK ) = 0;
	virtual void Wall(   UINT, UINT, opal::DIX, opal::COLOR = opal::BLANK ) = 0;
	virtual void Corner( UINT, UINT, UINT,      opal::COLOR = opal::BLANK ) = 0;
};

template<typename VIEW>class MAPPER_VIEW : public MAPPER_VIEW_I {
protected:
	std::shared_ptr<VIEW>	view{nullptr};
	opal::SSIZE2U			size{0,0};

public:
	void Size( UINT w, UINT h ){ size = {w,h};	}

public:
	void Clear( void ) override;

public:
	void Floor(  UINT, UINT,            opal::COLOR = opal::BLANK ) override;
	void Wall(   UINT, UINT, opal::DIX, opal::COLOR = opal::BLANK ) override;
	void Corner( UINT, UINT, UINT,      opal::COLOR = opal::BLANK ) override;
};

// End Of File

