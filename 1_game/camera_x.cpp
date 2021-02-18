//========================================
// camera_x.cpp
//========================================
#include "camera_x.hpp"

//----------------------------------------
// CAMERA X
//----------------------------------------
using namespace opal;

//----------------------------------------
//----------------------------------------
void CAMERA_X::Init( const char* p ){

	DRAW3L::Init( p );

	armh.Open( this );
	armh.Parent( this );

	armv.Open( this );
	armv.Parent( &armh );

	camera.Open( this );
	camera.Parent( &armv );
}

//----------------------------------------
//----------------------------------------
void CAMERA_X::Free( void ){

	camera.Close();
	armv.Close();
	armh.Close();

	DRAW3L::Free();
}

//----------------------------------------
//----------------------------------------
auto CAMERA_X::operator ()( void ) const->const opal::CAMERAX* { return &camera;	}

//----------------------------------------
//----------------------------------------
void CAMERA_X::SetArmV( float v ){ armv.SetTransY( v );	}
void CAMERA_X::SetArmH( float h ){ armh.SetTransZ( h );	}
void CAMERA_X::AddArmV( float v ){ armv.AddTransY( v );	}
void CAMERA_X::AddArmH( float h ){ armh.AddTransZ( h );	}
auto CAMERA_X::GetArmV( void ) const->float{ return armv.GetTransY();	}
auto CAMERA_X::GetArmH( void ) const->float{ return armh.GetTransZ();	}

//----------------------------------------
//----------------------------------------
void CAMERA_X::SetTilt( float t ){ camera.SetRotateX( t );	}
void CAMERA_X::SetPan(  float p ){ camera.SetRotateY( p );	}
void CAMERA_X::SetZoom( float z ){ camera.SetFov( z );		}
void CAMERA_X::AddTilt( float t ){ camera.AddRotateX( t );	}
void CAMERA_X::AddPan(  float p ){ camera.AddRotateY( p );	}
void CAMERA_X::AddZoom( float z ){ camera.AddFov( z );		}
auto CAMERA_X::GetTilt( void ) const->float{ return camera.GetRotateX();	}
auto CAMERA_X::GetPan(  void ) const->float{ return camera.GetRotateY();	}
auto CAMERA_X::GetZoom( void ) const->float{ return camera.GetFov();		}

//----------------------------------------
//----------------------------------------
#include "pad.hpp"

void CAMERA_X::ObjFunc( void ){

	printd( "CAMERA\n" );
	printd( "H[R/F] : %f\n", GetArmH() );
	printd( "V[T/G] : %f\n", GetArmV() );
	printd( "T[Y/H] : %f\n", DEG( GetTilt() ) );
	printd( "P[U/I] : %f\n", DEG( GetPan()  ) );
	printd( "Z[J/K] : %f\n", GetZoom() );
	printd( "\n" );

	if ( PADX::KeyPush( KEY_LSHIFT ) ) {
		const auto	ms = 0.04f;
		const auto	rs = RAD( 4.0f );
		const auto	zs = 0.01f;

		if ( PADX::KeyPush( KEY_R ) ) { AddArmH( +ms ); }
		if ( PADX::KeyPush( KEY_F ) ) { AddArmH( -ms ); }
		if ( PADX::KeyPush( KEY_T ) ) { AddArmV( +ms ); }
		if ( PADX::KeyPush( KEY_G ) ) { AddArmV( -ms ); }

		if ( PADX::KeyPush( KEY_Y ) ) { AddTilt( +rs ); }
		if ( PADX::KeyPush( KEY_H ) ) { AddTilt( -rs ); }
		if ( PADX::KeyPush( KEY_U ) ) { AddPan(  +rs ); }
		if ( PADX::KeyPush( KEY_I ) ) { AddPan(  -rs ); }

		if ( PADX::KeyPush( KEY_J ) ) { AddZoom( +zs ); }
		if ( PADX::KeyPush( KEY_K ) ) { AddZoom( -zs ); }
	}
}

// End Of File
