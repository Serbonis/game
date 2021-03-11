//========================================
// status.cpp
//========================================
#include "status.hpp"
#include "layout.hpp"

#include "rect2.hpp"
#include "font.hpp"
#include "texture.hpp"

#include "gauge.hpp"
#include "face.hpp"

//----------------------------------------
// FRAME - STATUS
//----------------------------------------
using namespace opal;
using namespace LAYOUT;

//----------------------------------------
//----------------------------------------
class STATUS_VIEW final : public DRAWL {
private:
	static constexpr float	FRAME_STATUS_MARGIN_W	= 16.f;
	static constexpr float	FRAME_STATUS_MARGIN_H	= 16.f;
	static constexpr float	FRAME_STATUS_OFFSET_X	= 16.f;
	static constexpr float	FRAME_STATUS_OFFSET_Y	= 16.f;

	static constexpr float	status_mw	= 4.0f;
	static constexpr float	status_mh	= 4.0f;
	static constexpr float	font_w		= 16;
	static constexpr float	font_h		= 24;

	static constexpr float	FRAME_STATUS_FACE_W	= font_w * 7;

	static constexpr float	FRAME_STATUS_FACE_H	= FRAME_STATUS_FACE_W;
	static constexpr float	FRAME_STATUS_HP_H	= font_h;
	static constexpr float	FRAME_STATUS_MP_H	= FRAME_STATUS_HP_H;
	static constexpr float	FRAME_STATUS_BACK_H	= FRAME_STATUS_FACE_H + FRAME_STATUS_HP_H + FRAME_STATUS_MP_H + status_mh * 4;

	static constexpr float	FRAME_STATUS_FACE_X = status_mw;
	static constexpr float	FRAME_STATUS_NAME_X = FRAME_STATUS_FACE_X + FRAME_STATUS_FACE_W + status_mw;
	static constexpr float	FRAME_STATUS_HP_X	= FRAME_STATUS_FACE_X - font_w/2;
	static constexpr float	FRAME_STATUS_MP_X	= FRAME_STATUS_HP_X;

	static constexpr float	FRAME_STATUS_FACE_Y	= status_mh;
	static constexpr float	FRAME_STATUS_NAME_Y	= FRAME_STATUS_FACE_Y;
	static constexpr float	FRAME_STATUS_HP_Y	= FRAME_STATUS_FACE_H + status_mh;
	static constexpr float	FRAME_STATUS_MP_Y	= FRAME_STATUS_HP_Y + font_h + status_mh;

private:
	FACE	face;
	RECT2	back;
	FONT	name;
	GAUGE	hp;
	GAUGE	mp;

public:
	void Init( const char* = nullptr ) override;
	void Free( void ) override;

public:
	void Index( UINT );

public:
	void Name( const std::string& );
	void Name( void );
	void Face( TEXTURE* );

public:
	void ValHP( void );
	void ValHP( float, bool );
	void ValMP( float, bool );
	void MaxHP( float );
	void MaxMP( float );
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
void FRAME_STATUS::Name(  UINT n, const std::string& s ){ if ( status.count( n ) ){ status.at( n )->Name( s ); }	}
void FRAME_STATUS::Name(  UINT n ){ if ( status.count( n ) ){ status.at( n )->Name(); }	}

void FRAME_STATUS::Face(  UINT n, TEXTURE* t ){ if ( status.count( n ) ){ status.at( n )->Face( t ); }	}

void FRAME_STATUS::ValHP( UINT n ){ if ( status.count( n ) ){ status.at( n )->ValHP(); }	}
void FRAME_STATUS::ValHP( UINT n, float v, bool f ){ if ( status.count( n ) ){ status.at( n )->ValHP( v, f ); }	}
void FRAME_STATUS::ValMP( UINT n, float v, bool f ){ if ( status.count( n ) ){ status.at( n )->ValMP( v, f ); }	}
void FRAME_STATUS::MaxHP( UINT n, float m ){ if ( status.count( n ) ){ status.at( n )->MaxHP( m ); }	}
void FRAME_STATUS::MaxMP( UINT n, float m ){ if ( status.count( n ) ){ status.at( n )->MaxMP( m ); }	}

//----------------------------------------
//----------------------------------------
void FRAME_STATUS::ObjFunc( void ){

	auto	i = 0;
	for ( auto& [n,s] : status ) {
		s->Index( i++ );
	}
}

//----------------------------------------
//----------------------------------------
#if OPAL_DEBUG
void FRAME_STATUS::Debug( void ) const {}
#endif

//----------------------------------------
// STATUS VIEW
//----------------------------------------
void STATUS_VIEW::Init( const char* p ){

	const float	FRAME_STATUS_BACK_W	= FRAME_MASK_W * 2 - FRAME_STATUS_MARGIN_W * 2;
	const float	FRAME_STATUS_HP_W	= FRAME_STATUS_BACK_W - status_mw * 2;
	const float	FRAME_STATUS_MP_W	= FRAME_STATUS_HP_W;

	DRAWL::Init( p );
	back.Open( this );
	back.SetSize( FRAME_STATUS_BACK_W, FRAME_STATUS_BACK_H );
	back.SetColor( 0, FRAME_STATUS_BACK_COLOR[0] );
	back.SetColor( 1, FRAME_STATUS_BACK_COLOR[0] );
	back.SetColor( 2, FRAME_STATUS_BACK_COLOR[1] );
	back.SetColor( 3, FRAME_STATUS_BACK_COLOR[1] );
	back.Parent( this );

	face.Open( this );
	face.SetTrans( FRAME_STATUS_FACE_X, FRAME_STATUS_FACE_Y );
	face.Size( FRAME_STATUS_FACE_W, FRAME_STATUS_FACE_H );
	face.ColorWaku( WHITE );
	face.ColorBack( BLACK );
	face.Parent( this );

	name.Open( this );
	name.SetTrans( FRAME_STATUS_NAME_X, FRAME_STATUS_NAME_Y );
	name.Parent( this );

	hp.Open( this );
	hp.SetTrans( FRAME_STATUS_HP_X, FRAME_STATUS_HP_Y );
	hp.SetSize(  FRAME_STATUS_HP_W, FRAME_STATUS_HP_H );
	hp.SetColorBar(  GREEN );
	hp.SetColorWaku( WHITE );
	hp.SetColorBack( BLACK );
	hp.Parent( this );

	mp.Open( this );
	mp.SetTrans( FRAME_STATUS_MP_X, FRAME_STATUS_MP_Y );
	mp.SetSize(  FRAME_STATUS_MP_W, FRAME_STATUS_MP_H );
	mp.SetColorBar(  MAGENTA );
	mp.SetColorWaku( WHITE );
	mp.SetColorBack( BLACK );
	mp.Parent( this );
}

void STATUS_VIEW::Free( void ){

	mp.Close();
	hp.Close();

	name.Close();
	face.Close();
	back.Close();

	DRAWL::Free();
}

//----------------------------------------
//----------------------------------------
void STATUS_VIEW::Index( UINT i ){

	SetTrans( FRAME_STATUS_OFFSET_X,
			  FRAME_STATUS_OFFSET_Y + ( FRAME_STATUS_BACK_H + FRAME_STATUS_MARGIN_H ) * i );
}

//----------------------------------------
//----------------------------------------
void STATUS_VIEW::Name( const std::string& s ){ name.Print( s.c_str() );	}
void STATUS_VIEW::Name( void ){ name.Clear();	}

//----------------------------------------
//----------------------------------------
void STATUS_VIEW::Face( TEXTURE* t ){ face.Texture( t );	}

//----------------------------------------
//----------------------------------------
void STATUS_VIEW::ValHP( void ){ hp.SetVal();	}
void STATUS_VIEW::ValHP( float v, bool f ){ hp.SetVal( v, f );	}
void STATUS_VIEW::ValMP( float v, bool f ){ mp.SetVal( v, f );	}
void STATUS_VIEW::MaxHP( float m ){ hp.SetMax( m );	}
void STATUS_VIEW::MaxMP( float m ){ mp.SetMax( m );	}

// End Of File

