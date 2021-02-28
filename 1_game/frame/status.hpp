#pragma once
//========================================
// status.hpp
//========================================
#include "drawx.hpp"

//----------------------------------------
// FRAME - STATUS
//----------------------------------------
class FRAME_STATUS final : public opal::DRAWL {
public:
	void Init( const char* = nullptr ) override;
	void Free( void ) override;

private:
	std::map<UINT,std::shared_ptr<class STATUS_VIEW>>	status;

public:
	void Generate( UINT );
	void Destroy( UINT );
	void Destroy( void );

private:
	void ObjFunc( void ) override;

#if OPAL_DEBUG
public:
	void Debug( void ) const;
#endif
};

// End Of File

