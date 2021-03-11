//----------------------------------------
// gauge.cpp
//----------------------------------------
#include "gauge.hpp"

//----------------------------------------
// GAUGE
//----------------------------------------
using namespace opal;

#include "mover.hpp"
#include "font.hpp"
#include "waku2.hpp"
#include "rect2.hpp"

class GAUGE_VIEW final :
	public DRAWL,
	public MOVER1
{
private:
	static constexpr float	font_w = 16;
	static constexpr float	font_h = 24;

private:
	FONT	num[3];
	RECT2	bar;
	WAKU2	waku;
	RECT2	back;

private:
	float	now;
	float	val;
	float	max;
	float	time;

private:
	std::function<void(void)>	update;

public:
	void Init( const char* = nullptr ) override;
	void Free( void ) override;

public:
	void SetVal( float, bool );
	void SetVal( void  );
	void SetMax( float );

public:
	void ColorBar( UINT );
	void ColorBar( UINT, UINT );
	void ColorBar( UINT, UINT, UINT, UINT );
	void ColorBack( UINT );
	void ColorBack( UINT, UINT );
	void ColorBack( UINT, UINT, UINT, UINT );
	void ColorWaku( UINT );

public:
	static constexpr float	margin_h = 4;

	void Horizontal( float, float );
	void Vertical(   float, float );
	void Horizontal( void );
	void Vertical(   void );

private:
	void number( void );
	void horizontal( void );
	void vertical(   void );

private:
	void ObjFunc( void ) override;
};

//----------------------------------------
//----------------------------------------
void GAUGE::Init( const char* p ){

	DRAWL::Init( p );

	makeshared( gauge );

	gauge->Open( this );
	gauge->Parent( this );
	gauge->Horizontal( 0, 0 );
	gauge->Horizontal();
}

void GAUGE::Free( void ){

	if ( gauge ) {
		gauge->Close();
		gauge = nullptr;
	}

	DRAWL::Free();
}

//----------------------------------------
//----------------------------------------
void GAUGE::SetStyle( STYLE s ){

	if ( style == s ) {
		return;
	}

	switch ( style = s ) {
	case STYLE::HORIZONTAL: gauge->Horizontal();	break;
	case STYLE::VERTICAL  : gauge->Vertical();		break;
	}
}

auto GAUGE::GetStyle( void ) const->STYLE{ return style;	}

//----------------------------------------
//----------------------------------------
void GAUGE::SetSize_( float w, float h ){

	switch ( style ) {
	case STYLE::HORIZONTAL: gauge->Horizontal( w, h );	break;
	case STYLE::VERTICAL  : gauge->Vertical(   w, h );	break;
	}
}

//----------------------------------------
//----------------------------------------
void GAUGE::SetVal( float v, bool f ){ gauge->SetVal( val = v, f );	}
void GAUGE::SetVal( void ){ gauge->SetVal();	}
void GAUGE::SetMax( float m ){ gauge->SetMax( max = m );	}
auto GAUGE::GetVal( void ) const->float{ return val;	}
auto GAUGE::GetMax( void ) const->float{ return max;	}

//----------------------------------------
//----------------------------------------
void GAUGE::SetColorBar(  UINT c ){ gauge->ColorBar(  c );	}
void GAUGE::SetColorBack( UINT c ){ gauge->ColorBack( c );	}
void GAUGE::SetColorWaku( UINT c ){ gauge->ColorWaku( c );	}

void GAUGE::SetColorBar(  UINT c0, UINT c1 ){ gauge->ColorBar(  c0, c1 );	}
void GAUGE::SetColorBack( UINT c0, UINT c1 ){ gauge->ColorBack( c0, c1 );	}

void GAUGE::SetColorBar(  UINT c0, UINT c1, UINT c2, UINT c3 ){ gauge->ColorBar(  c0, c1, c2, c3 );	}
void GAUGE::SetColorBack( UINT c0, UINT c1, UINT c2, UINT c3 ){ gauge->ColorBack( c0, c1, c2, c3 );	}

//----------------------------------------
// GAUGE_VIEW
//----------------------------------------
//----------------------------------------
//----------------------------------------
void GAUGE_VIEW::Init( const char* p ){

	DRAWL::Init( p );

	for ( auto& n : num ) {
		n.Open( this );
		n.Parent( this );
	}

	back.Open( this );
	back.Parent( this );
	bar.Open( this );
	bar.Parent( this );
	waku.Open( this );
	waku.Parent( this );

	now = 0;
	MOVER1::InitPromoterPosition();
	MOVER1::SetPromoterUpdate( [&](auto){ now = MOVER1::GetPromoterPosition(); } );
	time = SEC( 0.5f );
}

void GAUGE_VIEW::Free( void ){

	waku.Close();
	bar.Close();
	back.Close();

	for ( auto& n : num ) {
		n.Close();
	}

	DRAWL::Free();
}

//----------------------------------------
//----------------------------------------
void GAUGE_VIEW::SetVal( float v, bool f ){

	if ( f ) {
		if ( FNEQ( val, v ) ) {
			MOVER1::SetPromoterPosition( now, val = v );
			MOVER1::PromoterPlay( time );
		}
	} else {
		now = val = v;
		MOVER1::PromoterStop();
	}
}

void GAUGE_VIEW::SetVal( void ){

	MOVER1::PromoterStop();
}

void GAUGE_VIEW::SetMax( float m ){ max = m;	}

//----------------------------------------
//----------------------------------------
void GAUGE_VIEW::ColorBar(  UINT c ){ bar. SetColor( c );	}
void GAUGE_VIEW::ColorBack( UINT c ){ back.SetColor( c );	}
void GAUGE_VIEW::ColorWaku( UINT c ){ waku.SetColor( c );	}

void GAUGE_VIEW::ColorBar(  UINT c0, UINT c1 ){ bar. SetColor( c0, c1 );	}
void GAUGE_VIEW::ColorBack( UINT c0, UINT c1 ){ back.SetColor( c0, c1 );	}

void GAUGE_VIEW::ColorBar(  UINT c0, UINT c1, UINT c2, UINT c3 ){ bar. SetColor( c0, c1, c2, c3 );	}
void GAUGE_VIEW::ColorBack( UINT c0, UINT c1, UINT c2, UINT c3 ){ back.SetColor( c0, c1, c2, c3 );	}

//----------------------------------------
//----------------------------------------
void GAUGE_VIEW::Horizontal( float w, float h ){

	const auto	sw = w - font_w * 8;
	const auto	sh = h - margin_h * 2;

	bar. SetSize( sw, sh );
	waku.SetSize( sw, sh );
	back.SetSize( sw, sh );
}

void GAUGE_VIEW::Horizontal( void ){

	num[0].SetTrans( font_w * 0, font_h * 0 );
	num[1].SetTrans( font_w * 3, font_h * 0 );
	num[2].SetTrans( font_w * 4, font_h * 0 );
	bar. SetTrans(   font_w * 8, margin_h + 4 );
	back.SetTrans(   font_w * 8, margin_h + 4 );
	waku.SetTrans(   font_w * 8, margin_h + 4 );

	update = [&]{ horizontal();	};
}

void GAUGE_VIEW::Vertical( float w, float h ){}
void GAUGE_VIEW::Vertical( void ){}

//----------------------------------------
//----------------------------------------
void GAUGE_VIEW::number( void ){

	num[0].Print( "%03d", ( int )now );
	num[1].Print( "/" );
	num[2].Print( "%03d", ( int )max );
}

void GAUGE_VIEW::horizontal( void ){

	number();

	if ( !FZERO( max ) ) {
		bar.SetScaleX( now/max );
	} else {
		bar.SetScaleX( 0 );
	}
}

void GAUGE_VIEW::vertical( void ){}

//----------------------------------------
//----------------------------------------
void GAUGE_VIEW::ObjFunc( void ){

	if ( update ) {
		MOVER1::PromoterUpdate();
		update();
	}
}

// End Of File
