//----------------------------------------
// face.cpp
//----------------------------------------
#include "face.hpp"

//----------------------------------------
// FACE
//----------------------------------------
using namespace opal;

#include "waku2.hpp"
#include "rect2.hpp"
#include "texture.hpp"

class FACE_VIEW final : public DRAWL {
private:
	RECT2	face;
	WAKU2	waku;
	RECT2	back;

public:
	void Init( const char* = nullptr ) override;
	void Free( void ) override;

public:
	void Size( float, float );
	void Texture( const TEXTURE* );

public:
	void ColorBack( UINT );
	void ColorWaku( UINT );
};

//----------------------------------------
//----------------------------------------
void FACE::Init( const char* p ){

	DRAWL::Init( p );

	makeshared( face );

	face->Open( this );
	face->Parent( this );
}

void FACE::Free( void ){

	if ( face ) {
		face->Close();
		face = nullptr;
	}

	DRAWL::Free();
}

//----------------------------------------
//----------------------------------------
void FACE::Size( float w, float h ){ face->Size( w, h );	}

//----------------------------------------
//----------------------------------------
void FACE::Texture( const TEXTURE* t ){ face->Texture( t );	}

//----------------------------------------
//----------------------------------------
void FACE::ColorWaku( UINT c ){ face->ColorWaku( c );	}
void FACE::ColorBack( UINT c ){ face->ColorBack( c );	}

//----------------------------------------
//----------------------------------------
void FACE_VIEW::Init( const char* p ){

	DRAWL::Init( p );

	back.Open( this );
	face.Open( this );
	waku.Open( this );

	back.Parent( this );
	face.Parent( this );
	waku.Parent( this );
}

void FACE_VIEW::Free( void ){

	waku.Close();
	face.Close();
	back.Close();

	DRAWL::Free();
}

//----------------------------------------
//----------------------------------------
void FACE_VIEW::Size( float w, float h ){

	face.SetSize( w, h );
	back.SetSize( w, h );
	waku.SetSize( w, h );
}

//----------------------------------------
//----------------------------------------
void FACE_VIEW::Texture( const TEXTURE* t ){ face.SetTexture( t );	}

//----------------------------------------
//----------------------------------------
void FACE_VIEW::ColorBack( UINT c ){ back.SetColor( c );	}
void FACE_VIEW::ColorWaku( UINT c ){ waku.SetColor( c );	}

// End Of File
