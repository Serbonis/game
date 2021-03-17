//========================================
// minimap_v.cpp
//========================================
#include "minimap_v.hpp"

//----------------------------------------
// MINIMAP - VIEW
//----------------------------------------
using namespace opal;
using namespace LAYOUT;

namespace {
	constexpr float	FRAME_MINIMAP_BUFFER	= std::pow( 2, MINIMAP_VIEW::FRAME_MINIMAP_ORDER );
	constexpr UINT	FRAME_MINIMAP_GRID_N	= 16;
	constexpr UINT	FRAME_MINIMAP_GRID_M	= FRAME_MINIMAP_GRID_N;
	constexpr float	FRAME_MINIMAP_GRID_B	= FRAME_MINIMAP_BUFFER/FRAME_MINIMAP_GRID_M;
	constexpr float	FRAME_MINIMAP_GRID_R	= 1/16.f;

	const std::string	FILE_PATH = "../Data/minimap/";
	const std::string	TEXTURE_ARROW = "arrow.png";
};

//----------------------------------------
//---------------------------------------
void MINIMAP_VIEW::Init( const char* p ){

	DRAWL::Init( p );

	const auto	minimap_size = ( FRAME_MINIMAP_W < FRAME_MINIMAP_H ) ? FRAME_MINIMAP_W : FRAME_MINIMAP_H;

	grid_size = minimap_size/FRAME_MINIMAP_GRID_N;

	mapper.Open( this );
	mapper.SetTrans( FRAME_MINIMAP_W/2, FRAME_MINIMAP_H/2 );
	mapper.SetSize( minimap_size );
	mapper.Canvas( SSIZE{FRAME_MINIMAP_W,FRAME_MINIMAP_H} );
	mapper.Parent( this );
	SetUpdater( "MAPPER", [&]{ mapper.Canvas( waku.WorldTrans() ); } );

	waku.Open( this );
	waku.SetSize( FRAME_MINIMAP_W, FRAME_MINIMAP_H );
	waku.Parent( this );

	name.Open( this );
	name.Parent( this );

	texture_arrow.Init( FILE_PATH + TEXTURE_ARROW );

	arrow.Open( this );
	arrow.SetSize( grid_size/2 );
	arrow.SetPivot();
	arrow.Parent( this );
	arrow.SetTexture( texture_arrow );

	//polygon_radar.Init();

	//radar.Open( this );
	//radar.SetPolygon( polygon_radar );
	//radar.Parent( &arrow );

	Move( 0, 0 );
	MapName();
}

void MINIMAP_VIEW::Free( void ){

	//polygon_radar.Free();
	texture_arrow.Free();

	//radar.Close();
	arrow.Close();
	name.Close();
	mapper.Close();
	waku.Close();

	DRAWL::Free();
}

//arrow.SetTrans();
//arrow.SetRotate();

//---------------------------------------
//---------------------------------------
void MINIMAP_VIEW::Clear( void ){

	for ( auto i = 0UL; i < FRAME_MINIMAP_GRID_M; i++ ) {
		for ( auto j = 0UL; j < FRAME_MINIMAP_GRID_M; j++ ) {
			Floor( j, i );
		}
	}
}

//---------------------------------------
//---------------------------------------
void MINIMAP_VIEW::Floor( UINT x, UINT y, COLOR c ){

	if ( const auto p = MAPPER::FloorRect( x, y, FRAME_MINIMAP_GRID_B ) ) {
		mapper.Mapping( p->x, p->y, p->w, p->h, c );
	}
}

void MINIMAP_VIEW::Wall( UINT x, UINT y, DIX d, COLOR c ){

	if ( const auto p = MAPPER::WallRect( x, y, d, FRAME_MINIMAP_GRID_B, FRAME_MINIMAP_GRID_M, FRAME_MINIMAP_GRID_R ) ) {
		mapper.Mapping( p->x, p->y, p->w, p->h, c );
	}
}

void MINIMAP_VIEW::Corner( UINT x, UINT y, UINT w, COLOR c ){

	const UINT	dic[] = { DIC_I,DIC_U,DIC_T,DIC_H };

	for ( const auto& d : dic ) {
		if ( w & d ){
			if ( const auto p = MAPPER::CornerRect( x, y, d, FRAME_MINIMAP_GRID_B, FRAME_MINIMAP_GRID_M, FRAME_MINIMAP_GRID_R ) ) {
				mapper.Mapping( p->x, p->y, p->w, p->h, c );
			}
		}
	}
}

//---------------------------------------
//---------------------------------------
void MINIMAP_VIEW::Move( float x, float y ){

	mapper.SetPivot( x * grid_size,
					 y * grid_size );
}

//---------------------------------------
//---------------------------------------
void MINIMAP_VIEW::MapName( const std::string& s ){

	const float	x = FRAME_MINIMAP_X + FRAME_MINIMAP_W;
	const float	y = FRAME_MINIMAP_Y + FRAME_MINIMAP_H - 16.f;

	name.Print( s.c_str() );
	name.Center( x, y );
}

//---------------------------------------
//---------------------------------------
void MINIMAP_VIEW::WakuColor( UINT c ){

	waku.SetColor( c );
}

// End Of File
