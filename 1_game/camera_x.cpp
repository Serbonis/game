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

	ACTOR_X::Init( p );

	view.Open();

	armh.Open( &view );
	armh.Parent( this );

	armv.Open( &view );
	armv.Parent( &armh );

	camera.Open( &view );
	camera.Parent( &armv );

	SetMoveSpeed( 0.04f );
	SetRotateSpeed( RAD( 4.0f ) );

	SetUpdater( "ACTOR_C", [&]{ ACTOR_C::Updater( this ); } );
}

//----------------------------------------
//----------------------------------------
void CAMERA_X::Free( void ){

	camera.Close();
	armv.Close();
	armh.Close();
	view.Close();

	ACTOR_X::Free();
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
#if OPAL_DEBUG
#include "pad.hpp"
#include "scene_game.hpp"

void CAMERA_X::Debug( float ms, float rs, float zs ){

	printd( "CAMERA : %s\n", GetName() );

	if ( !Parent() ) {
		const auto	t = GetTrans();
		const auto	p = Game::MapPoint(  t );
		const auto	v = Game::MapVector( p );

		printd( "V2P [%02d,%02d]\n", p.x, p.y );
		printd( "P2V [%f,%f]\n", v.x, v.z );
		printd( "F[A/D] : %f, %f\n", t.x, t.z );
		printd( "B[W/S] : %f\n", GetMoveSpeed() );
		printd( "R[Q/E] : %f\n", DEG( GetRotateSpeed() ) );
		printd( "H[SPC] : %f\n", t.y );

		if ( PADX::KeyPush( KEY_W ) ) { MoveF();	}
		if ( PADX::KeyPush( KEY_S ) ) { MoveB();	}
		if ( PADX::KeyPush( KEY_A ) ) { MoveL();	}
		if ( PADX::KeyPush( KEY_D ) ) { MoveR();	}
		if ( PADX::KeyTrig( KEY_Q ) ) { RotateL(); 	}
		if ( PADX::KeyTrig( KEY_E ) ) { RotateR(); 	}
	}

	printd( "H[R/F] : %f\n", GetArmH() );
	printd( "V[T/G] : %f\n", GetArmV() );
	printd( "T[Y/H] : %f\n", DEG( GetTilt() ) );
	printd( "P[U/I] : %f\n", DEG( GetPan()  ) );
	printd( "Z[J/K] : %f\n", GetZoom() );
	printd( "\n" );

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
#endif

// End Of File
