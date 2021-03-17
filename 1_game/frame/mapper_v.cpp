//========================================
// mapper_v.cpp
//========================================
#include "mapper_v.hpp"

//----------------------------------------
// MAPPER - VIEW
//----------------------------------------
using namespace opal;

//----------------------------------------
//----------------------------------------
template<typename VIEW>void MAPPER_VIEW<VIEW>::Clear( void ){ view->Clear(); }

template<typename VIEW>void MAPPER_VIEW<VIEW>::Floor(  UINT x, UINT y,         COLOR c ){ view->Floor(  x, y,    c );	}
template<typename VIEW>void MAPPER_VIEW<VIEW>::Wall(   UINT x, UINT y, DIX  d, COLOR c ){ view->Wall(   x, y, d, c );	}
template<typename VIEW>void MAPPER_VIEW<VIEW>::Corner( UINT x, UINT y, UINT w, COLOR c ){ view->Corner( x, y, w, c );	}

//----------------------------------------
//----------------------------------------
#include "radar_v.hpp"

template void MAPPER_VIEW<RADAR_VIEW>::Clear( void );

template void MAPPER_VIEW<RADAR_VIEW>::Floor(  UINT, UINT,       COLOR );
template void MAPPER_VIEW<RADAR_VIEW>::Wall(   UINT, UINT, DIX,  COLOR );
template void MAPPER_VIEW<RADAR_VIEW>::Corner( UINT, UINT, UINT, COLOR );

//----------------------------------------
//----------------------------------------
#include "minimap_v.hpp"

template void MAPPER_VIEW<MINIMAP_VIEW>::Clear( void );

template void MAPPER_VIEW<MINIMAP_VIEW>::Floor(  UINT, UINT,       COLOR );
template void MAPPER_VIEW<MINIMAP_VIEW>::Wall(   UINT, UINT, DIX,  COLOR );
template void MAPPER_VIEW<MINIMAP_VIEW>::Corner( UINT, UINT, UINT, COLOR );

// End Of File

