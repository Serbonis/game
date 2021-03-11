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

public:
	void Name(  UINT, const std::string& );
	void Name(  UINT );
	void Face(  UINT, class TEXTURE* = nullptr );
	void ValHP( UINT );
	void ValHP( UINT, float, bool = true );
	void ValMP( UINT, float, bool = true );
	void MaxHP( UINT, float );
	void MaxMP( UINT, float );

private:
	void ObjFunc( void ) override;

#if OPAL_DEBUG
public:
	void Debug( void ) const;
#endif
};

// End Of File

