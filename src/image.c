/*
 * Cairo library: image
 *
 * Copyright 2020 Rafał Jopek ( rafaljopek at hotmail com )
 *
 * Copyright 2009 Mindaugas Kavaliauskas <dbtopas at dbtopas.lt>
 *
 * Image Surfaces
 * Image Surfaces — Rendering to memory buffers
 *
 * Types and Values
 *
 * #define CAIRO_HAS_IMAGE_SURFACE
 * enum    cairo_format_t
 *
 */

#include "hbcairo.h"

// int cairo_format_stride_for_width( cairo_format_t format, int width );
HB_FUNC( CAIRO_FORMAT_STRIDE_FOR_WIDTH )
{
#ifdef CAIRO_HAS_IMAGE_SURFACE
   hb_retni( cairo_format_stride_for_width( ( cairo_format_t ) hb_parni( 1 ), hb_parni( 2 ) ) );
#else
   hb_retni( NULL );
#endif
}

// cairo_surface_t* cairo_image_surface_create( cairo_format_t format, int width, int height );
HB_FUNC( CAIRO_IMAGE_SURFACE_CREATE )
{
#ifdef CAIRO_HAS_IMAGE_SURFACE
   hb_cairo_surface_ret( cairo_image_surface_create( ( cairo_format_t ) hb_parni( 1 ), hb_parni( 2 ), hb_parni( 3 ) ) );
#else
   hb_retptr( NULL );
#endif
}

// cairo_surface_t* cairo_image_surface_create_for_data( unsigned char *data, cairo_format_t format, int width, int height, int stride );
HB_FUNC( CAIRO_IMAGE_SURFACE_CREATE_FOR_DATA )
{
#ifdef CAIRO_HAS_IMAGE_SURFACE
   hb_cairo_surface_ret( cairo_image_surface_create_for_data( ( unsigned char * ) hb_parptr( 1 ), ( cairo_format_t ) hb_parni( 2 ), hb_parni( 3 ), hb_parni( 4 ), hb_parni( 5 ) ) );
#else
   hb_retptr( NULL );
#endif
}

// unsigned char* cairo_image_surface_get_data( cairo_surface_t *surface );

// cairo_format_t cairo_image_surface_get_format( cairo_surface_t *surface );

// int cairo_image_surface_get_width( cairo_surface_t *surface );

// int cairo_image_surface_get_height( cairo_surface_t *surface );

// int cairo_image_surface_get_stride( cairo_surface_t *surface );
