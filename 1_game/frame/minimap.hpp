#pragma once
//========================================
// minimap.hpp
//========================================
#include "drawx.hpp"
#include "mapper_v.hpp"

//----------------------------------------
// FRAME - MINIMAP
//----------------------------------------
class FRAME_MINIMAP final :
	public opal::DRAWL,
	public MAPPER_VIEW<class MINIMAP_VIEW>
{
	using MAPPER_VIEW::size;

public:
	void Init( const char* = nullptr ) override;
	void Free( void ) override;

public:
	void Clear( void );

public:
	void Move( float, float );

public:
	void MapName( const std::string& );

private:
	void ObjFunc( void ) override;

#if OPAL_DEBUG
public:
	void Debug( void ) const;
#endif
};

// End Of File

