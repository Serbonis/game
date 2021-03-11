#pragma once
//========================================
// radar.hpp
//========================================
#include "drawx.hpp"

//----------------------------------------
// FRAME - RADAR
//----------------------------------------
class FRAME_RADAR final : public opal::DRAWL {
public:
	void Init( const char* = nullptr ) override;
	void Free( void ) override;

private:
	std::shared_ptr<class RADAR_VIEW>	radar;

public:
	void Clear( void );

public:
	void Move( UINT, UINT );
	void Turn( float );

private:
	void ObjFunc( void ) override;

#if OPAL_DEBUG
public:
	void Debug( void ) const;
#endif
};

// End Of File

