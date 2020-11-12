/*
 * Cairo library: image
 *
 * Copyright 2009 Mindaugas Kavaliauskas <dbtopas at dbtopas.lt>
 *
 */

#include "hbcairo.h"

HB_FUNC( CAIRO_IMAGE_SURFACE_CREATE )
{
#ifdef CAIRO_HAS_IMAGE_SURFACE
   hb_cairo_surface_ret( cairo_image_surface_create( ( cairo_format_t ) hb_parni( 1 ), hb_parni( 2 ), hb_parni( 3 ) ) );
#else
   hb_retptr( NULL );
#endif
}

HB_FUNC( CAIRO_IMAGE_SURFACE_CREATE_FOR_DATA )
{
#ifdef CAIRO_HAS_IMAGE_SURFACE
   hb_cairo_surface_ret( cairo_image_surface_create_for_data( ( unsigned char * ) hb_parptr( 1 ), ( cairo_format_t ) hb_parni( 2 ), hb_parni( 3 ), hb_parni( 4 ), hb_parni( 5 ) ) );
#else
   hb_retptr( NULL );
#endif
}
