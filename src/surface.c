/*
 * Cairo library: surface
 *
 * Copyright 2009 Mindaugas Kavaliauskas <dbtopas at dbtopas.lt>
 *
 */

#include "hbcairo.h"

HB_FUNC( CAIRO_SURFACE_STATUS )
{
   cairo_surface_t * pSurface = hb_cairo_surface_param( 1 );

   if( pSurface )
      hb_retni( cairo_surface_status( pSurface ) );
}
