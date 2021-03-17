//========================================
// radar_v.cpp
//========================================
#include "radar_v.hpp"

//----------------------------------------
// RADAR - VIEW
//----------------------------------------
using namespace opal;
using namespace LAYOUT;

namespace {
	constexpr float	FRAME_RADAR_BUFFER	= std::pow( 2, RADAR_VIEW::FRAME_RADAR_ORDER );
	constexpr UINT	FRAME_RADAR_GRID_N	= 7;
	constexpr UINT	FRAME_RADAR_GRID_M	= 16;
	constexpr float	FRAME_RADAR_GRID_B	= FRAME_RADAR_BUFFER/FRAME_RADAR_GRID_M;
	constexpr float	FRAME_RADAR_GRID_R	= 1/16.f;

	const std::string	FILE_PATH = "../Data/radar/";
	const std::string	TEXTURE_ARROW = "arrow.png";
	const std::string	TEXTURE_DIR[] = { "dir_n.png", "dir_e.png", "dir_s.png", "dir_w.png", };
}

//----------------------------------------
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

	texture_arrow.Init( FILE_PATH + TEXTURE_ARROW );

	arrow.Open( this );
	arrow.SetTrans( radar_size/2, radar_size/2 );
	arrow.SetSize( grid_size/2 );
	arrow.SetPivot();
	arrow.Parent( this );
	arrow.SetTexture( texture_arrow );

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
void RADAR_VIEW::Floor( UINT x, UINT y, COLOR c ){

	if ( const auto p = MAPPER::FloorRect( x, y, FRAME_RADAR_GRID_B ) ) {
		mapper.Mapping( p->x, p->y, p->w, p->h, c );
	}
}

void RADAR_VIEW::Wall( UINT x, UINT y, DIX d, COLOR c ){

	if ( const auto p = MAPPER::WallRect( x, y, d, FRAME_RADAR_GRID_B, FRAME_RADAR_GRID_M, FRAME_RADAR_GRID_R ) ) {
		mapper.Mapping( p->x, p->y, p->w, p->h, c );
	}
}

void RADAR_VIEW::Corner( UINT x, UINT y, UINT w, COLOR c ){

	const UINT	dic[] = { DIC_I,DIC_U,DIC_T,DIC_H };

	for ( const auto& d : dic ) {
		if ( w & d ){
			if ( const auto p = MAPPER::CornerRect( x, y, d, FRAME_RADAR_GRID_B, FRAME_RADAR_GRID_M, FRAME_RADAR_GRID_R ) ) {
				mapper.Mapping( p->x, p->y, p->w, p->h, c );
			}
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

	mapper.SetRotate( -r );
}

//---------------------------------------
//---------------------------------------
void RADAR_VIEW::WakuColor( UINT c ){

	waku.SetColor( c );
}

void RADAR_VIEW::ArrowColor( UINT c ){

	arrow.SetColor( c );
}

// End Of File
