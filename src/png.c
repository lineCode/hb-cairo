/*
 * Cairo library: png
 *
 * Copyright 2020 Rafał Jopek ( rafaljopek at hotmail com )
 *
 * Copyright 2009 Mindaugas Kavaliauskas <dbtopas at dbtopas.lt>
 *
 */

#include "hbcairo.h"

// cairo_surface_t * cairo_image_surface_create_from_png( const char *filename );
HB_FUNC( CAIRO_IMAGE_SURFACE_CREATE_FROM_PNG )
{
#ifdef CAIRO_HAS_PNG_FUNCTIONS
   hb_cairo_surface_ret( cairo_image_surface_create_from_png( hb_parc( 1 ) ) );
#else
   hb_retptr( NULL );
#endif
}

// cairo_status_t ( *cairo_read_func_t )( void *closure, unsigned char *data, unsigned int length );

// cairo_surface_t * cairo_image_surface_create_from_png_stream( cairo_read_func_t read_func, void *closure );

// cairo_status_t cairo_surface_write_to_png( cairo_surface_t *surface, const char *filename );
HB_FUNC( CAIRO_SURFACE_WRITE_TO_PNG )
{
#ifdef CAIRO_HAS_PNG_FUNCTIONS
   cairo_surface_t * pSurface = hb_cairo_surface_param( 1 );
   if( pSurface )
   {
      hb_retni( cairo_surface_write_to_png( pSurface, hb_parc( 2 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }

#else
   hb_cairo_surface_param( 1 ); /* Parameter validation */
   hb_retni( -1 );              /* There is no good CAIRO_STATUS_* for this */
#endif
}

// cairo_status_t ( *cairo_write_func_t )( void *closure, unsigned char *data, unsigned int length );

// cairo_status_t cairo_surface_write_to_png_stream( cairo_surface_t *surface, cairo_write_func_t write_func, void *closure );
