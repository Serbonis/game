//========================================
// status.cpp
//========================================
#include "status.hpp"
#include "layout.hpp"

#include "rect2.hpp"
#include "font.hpp"

//----------------------------------------
// FRAME - STATUS
//----------------------------------------
using namespace opal;
using namespace LAYOUT;

constexpr UINT	FRAME_STATUS_BACK_COLOR[2]	= { BLUE, BLACK };

//----------------------------------------
//----------------------------------------
class STATUS_VIEW final : public DRAWL {
private:
	RECT2	face;
	RECT2	back;
	FONT	name;

public:
	void Init( const char* p = nullptr ) override {

		DRAWL::Init( p );

		back.Open( this );
		back.SetSize( FRAME_STATUS_BACK_W, FRAME_STATUS_BACK_H );
		back.SetColor( 0, FRAME_STATUS_BACK_COLOR[0] );
		back.SetColor( 1, FRAME_STATUS_BACK_COLOR[0] );
		back.SetColor( 2, FRAME_STATUS_BACK_COLOR[1] );
		back.SetColor( 3, FRAME_STATUS_BACK_COLOR[1] );
		back.Parent( this );

		face.Open( this );
		face.SetOffset( FRAME_STATUS_FACE_X, FRAME_STATUS_FACE_Y );
		face.SetSize( FRAME_STATUS_FACE_W, FRAME_STATUS_FACE_H );
		face.SetColor( GRAY );
		face.Parent( this );

		name.Open( this );
		name.SetTrans( FRAME_STATUS_NAME_X, FRAME_STATUS_NAME_Y );
		name.Parent( this );
	}
	void Free( void ) override {

		name.Close();
		face.Close();
		back.Close();

		DRAWL::Free();
	}
};

//----------------------------------------
//----------------------------------------
void FRAME_STATUS::Init( const char* p ){

	DRAWL::Init( p );

}
void FRAME_STATUS::Free( void ){

	Destroy();
	DRAWL::Free();
}

//----------------------------------------
//----------------------------------------
void FRAME_STATUS::Generate( UINT n ){

	Destroy( n );

	const auto	s = makeshared( status[n] );

	s->Open( this );
	s->Parent( this );
}

void FRAME_STATUS::Destroy( UINT n ){

	if ( status.count( n ) ) {
		status.at( n )->Close();
		status.erase( n );
	}
}

void FRAME_STATUS::Destroy( void ){

	for ( auto& [n,s] : status ) {
		s->Close();
	}
	status.clear();
}

//----------------------------------------
//----------------------------------------
void FRAME_STATUS::ObjFunc( void ){

	auto	i = 0;
	for ( auto& [n,s] : status ) {
		s->SetTrans( FRAME_STATUS_OFFSET_X,
					 FRAME_STATUS_OFFSET_Y + ( FRAME_STATUS_H + FRAME_STATUS_MARGIN_H ) * i );
		i++;
	}
}

//----------------------------------------
//----------------------------------------
#if OPAL_DEBUG
void FRAME_STATUS::Debug( void ) const {

	printd( "STATUS[%d] %f %f\n", ( int )status.size(), GetTransX(), GetTransY() );

	for ( const auto& [n,s] : status ) {
		const auto	p = s->GetTrans();
		printd( "[%d] %f %f\n", ( int )n, p.x, p.y );

	}
}
#endif

// End Of File

