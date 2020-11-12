/*
 * Cairo library: png
 *
 * Copyright 2009 Mindaugas Kavaliauskas <dbtopas at dbtopas.lt>
 *
 */

#include "hbcairo.h"

HB_FUNC( CAIRO_IMAGE_SURFACE_CREATE_FROM_PNG )
{
#ifdef CAIRO_HAS_PNG_FUNCTIONS
   hb_cairo_surface_ret( cairo_image_surface_create_from_png( hb_parc( 1 ) ) );
#else
   hb_retptr( NULL );
#endif
}

HB_FUNC( CAIRO_SURFACE_WRITE_TO_PNG )
{
#ifdef CAIRO_HAS_PNG_FUNCTIONS
   cairo_surface_t * pSurface = hb_cairo_surface_param( 1 );
   if( pSurface )
      hb_retni( cairo_surface_write_to_png( pSurface, hb_parc( 2 ) ) );
#else
   hb_cairo_surface_param( 1 ); /* Parameter validation */
   hb_retni( -1 );              /* There is no good CAIRO_STATUS_* for this */
#endif
}
