//========================================
// radar.cpp
//========================================
#include "radar.hpp"
#include "layout.hpp"

#include "rect2.hpp"
#include "waku2.hpp"
#include "texture.hpp"

#include "mapper.hpp"

//----------------------------------------
// FRAME - RADAR
//----------------------------------------
using namespace opal;
using namespace LAYOUT;

namespace {
	const std::string	FILE_PATH = "../Data/radar/";
	const std::string	TEXTURE_ARROW = "arrow.png";
	const std::string	TEXTURE_DIR[] = { "dir_n.png", "dir_e.png", "dir_s.png", "dir_w.png", };
}

//----------------------------------------
//----------------------------------------
class RADAR_VIEW final : public DRAWL {
private:
	static constexpr UINT	FRAME_RADAR_ORDER	= 10;
	static constexpr float	FRAME_RADAR_BUFFER	= std::pow( 2, FRAME_RADAR_ORDER );
	static constexpr UINT	FRAME_RADAR_GRID_N	= 7;
	static constexpr UINT	FRAME_RADAR_GRID_M	= 16;
	static constexpr float	FRAME_RADAR_GRID_B	= FRAME_RADAR_BUFFER/FRAME_RADAR_GRID_M;
	static constexpr float	FRAME_RADAR_GRID_R	= 1/16.f;

private:
	TEXTURE	texture_arrow;
	TEXTURE	texture_dir[DIX_MAX];

private:
	RECT2	arrow;
	DRAWL	dix;
	RECT2	dir[DIX_MAX];

private:
	float	grid_size;

private:
	WAKU2	waku;
	MAPPER	mapper{FRAME_RADAR_ORDER};

public:
	void Init( const char* = nullptr ) override;
	void Free( void ) override;

public:
	void Clear( void );

public:
	void Move( UINT, UINT );
	void Turn( float );

public:
	void WakuColor(  UINT );
	void ArrowColor( UINT );

public:
	void Floor(  UINT, UINT,      COLOR = BLANK );
	void Wall(   UINT, UINT, DIX, COLOR = BLANK );
	void Corner( UINT, UINT, DIX, COLOR = BLANK );
};

//----------------------------------------
//----------------------------------------
void FRAME_RADAR::Init( const char* p ){

	DRAWL::Init( p );

	makeshared( radar );

	radar->Open( this );
	radar->Parent( this );

	size = {};
}

void FRAME_RADAR::Free( void ){

	if ( radar ) {
		radar->Close();
		radar = nullptr;
	}

	DRAWL::Free();
}

//----------------------------------------
//----------------------------------------
void FRAME_RADAR::Clear( void ){

	radar->WakuColor(  FRAME_RADAR_WAKU_COLOR[0]  );
	radar->ArrowColor( FRAME_RADAR_ARROW_COLOR[0] );

	radar->Clear();
}

//----------------------------------------
//----------------------------------------
void FRAME_RADAR::Size( UINT w, UINT h ){ size = {w,h};	}

//----------------------------------------
//----------------------------------------
void FRAME_RADAR::Floor(  UINT x, UINT y,        COLOR c ){ radar->Floor(  x, y,    c );	}
void FRAME_RADAR::Wall(   UINT x, UINT y, DIX d, COLOR c ){ radar->Wall(   x, y, d, c );	}
void FRAME_RADAR::Corner( UINT x, UINT y, DIX d, COLOR c ){ radar->Corner( x, y, d, c );	}

//----------------------------------------
//----------------------------------------
void FRAME_RADAR::Move( UINT x, UINT y ){

	radar->Move( x, size.h-1 - y );
}

void FRAME_RADAR::Turn( float r ){

	radar->Turn( r );
}

//----------------------------------------
//----------------------------------------
void FRAME_RADAR::ObjFunc( void ){}

//----------------------------------------
//----------------------------------------
#if OPAL_DEBUG
void FRAME_RADAR::Debug( void ) const {}
#endif

//----------------------------------------
// RADAR VIEW
//---------------------------------------
void RADAR_VIEW::Init( const char* p ){

	DRAWL::Init( p );

	const auto	radar_size = ( FRAME_RADAR_W < FRAME_RADAR_H ) ? FRAME_RADAR_W : FRAME_RADAR_H;

	grid_size = radar_size/FRAME_RADAR_GRID_N;

	mapper.Open( this );
	mapper.SetTrans( radar_size/2, radar_size/2 );
	mapper.SetSize( grid_size * FRAME_RADAR_GRID_M );
	mapper.Canvas( SSIZE{radar_size,radar_size} );
	mapper.Parent( this );
	SetUpdater( "MAPPER", [&]{ mapper.Canvas( waku.WorldTrans() ); } );

	waku.Open( this );
	waku.SetSize( radar_size );
	waku.Parent( this );

	arrow.Open( this );
	arrow.SetTrans( radar_size/2, radar_size/2 );
	arrow.SetSize( grid_size/2 );
	arrow.SetPivot();
	arrow.Parent( this );

	dix.Open( this );
	dix.Parent( &mapper );

	for ( auto i = 0UL; i < DIX_MAX; i++ ) {
		texture_dir[i].Init( FILE_PATH + TEXTURE_DIR[i] );

		constexpr float	dir_size = 32.f;

		dir[i].Open( this );
		dir[i].SetTexture( texture_dir[i] );
		dir[i].SetRotate( RAD( 90.f * i ) );
		dir[i].SetSize( dir_size );
		dir[i].SetPivot();
		dir[i].Parent( &dix );
	}

	dir[DIX_N].SetTrans( 0, -radar_size/2 );
	dir[DIX_S].SetTrans( 0, +radar_size/2 );
	dir[DIX_E].SetTrans( +radar_size/2, 0 );
	dir[DIX_W].SetTrans( -radar_size/2, 0 );

	texture_arrow.Init( FILE_PATH + TEXTURE_ARROW );

	arrow.SetTexture( texture_arrow );

	Move( 0, 0 );
	Turn( 0 );
}

void RADAR_VIEW::Free( void ){

	texture_arrow.Free();

	mapper.Close();
	waku.Close();
	arrow.Close();
	dix.Close();
	for ( auto i = 0UL; i < DIX_MAX; i++ ) {
		texture_dir[i].Free();
		dir[i].Close();
	}

	DRAWL::Free();
}

//---------------------------------------
//---------------------------------------
void RADAR_VIEW::Clear( void ){

	for ( auto i = 0UL; i < FRAME_RADAR_GRID_M; i++ ) {
		for ( auto j = 0UL; j < FRAME_RADAR_GRID_M; j++ ) {
			Floor( j, i );
		}
	}
}

//---------------------------------------
//---------------------------------------
void RADAR_VIEW::Move( UINT x, UINT y ){

	mapper.SetPivot(  ( x + 0.5f ) * grid_size,
					  ( y + 0.5f ) * grid_size );
}

//---------------------------------------
//---------------------------------------
void RADAR_VIEW::Turn( float r ){

	mapper.SetRotate( r );
}

//---------------------------------------
//---------------------------------------
void RADAR_VIEW::WakuColor( UINT c ){

	waku.SetColor( c );
}

void RADAR_VIEW::ArrowColor( UINT c ){

	arrow.SetColor( c );
}

//---------------------------------------
//---------------------------------------
inline static auto floor_rect( UINT x, UINT y, float s )->std::shared_ptr<SRECTF>{

	return std::make_shared<SRECTF>( s*x, s*y, s, s );
}

inline static auto wall_rect( UINT x, UINT y, DIX d, float s, UINT n, float r )->std::shared_ptr<SRECTF>{

	if ( d != DIX_MAX ) {
		const auto	t = s * r;
		const auto	p = s - t;
		const auto	w = s - t * 2;

		switch ( d ) {
		case DIX_N:return std::make_shared<SRECTF>( s*x+t, s*y,   w, t );
		case DIX_E:return std::make_shared<SRECTF>( s*x+p, s*y+t, t, w );
		case DIX_S:return std::make_shared<SRECTF>( s*x+t, s*y+p, w, t );
		case DIX_W:return std::make_shared<SRECTF>( s*x,   s*y+t, t, w );
		default:break;
		}
	}
	return nullptr;
}

inline static auto corner_rect( UINT x, UINT y, DIX d, float s, UINT n, float r )->std::shared_ptr<SRECTF>{

	if ( d != DIX_MAX ) {
		const auto	t = s * r;
		const auto	p = s - t;

		switch ( d ) {
		case DIX_N:return std::make_shared<SRECTF>( s*x,   s*y,   t, t );
		case DIX_E:return std::make_shared<SRECTF>( s*x+p, s*y,   t, t );
		case DIX_S:return std::make_shared<SRECTF>( s*x+p, s*y+p, t, t );
		case DIX_W:return std::make_shared<SRECTF>( s*x,   s*y+p, t, t );
		default:break;
		}
	}
	return nullptr;
}

void RADAR_VIEW::Floor( UINT x, UINT y, COLOR c ){

	if ( const auto p = floor_rect( x, y, FRAME_RADAR_GRID_B ) ) {
		mapper.Mapping( p->x, p->y, p->w, p->h, c );
	}
}

void RADAR_VIEW::Wall( UINT x, UINT y, DIX d, COLOR c ){

	if ( const auto p = wall_rect( x, y, d, FRAME_RADAR_GRID_B, FRAME_RADAR_GRID_M, FRAME_RADAR_GRID_R ) ) {
		mapper.Mapping( p->x, p->y, p->w, p->h, c );
	}
}

void RADAR_VIEW::Corner( UINT x, UINT y, DIX d, COLOR c ){

	if ( const auto p = corner_rect( x, y, d, FRAME_RADAR_GRID_B, FRAME_RADAR_GRID_M, FRAME_RADAR_GRID_R ) ) {
		mapper.Mapping( p->x, p->y, p->w, p->h, c );
	}
}

// End Of File

