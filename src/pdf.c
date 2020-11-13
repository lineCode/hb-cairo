/*
 * Cairo library: pdf
 *
 * Copyright 2009 Mindaugas Kavaliauskas <dbtopas at dbtopas.lt>
 *
 */

#include "hbcairo.h"
#include "cairo-pdf.h"

/*
 * enum                cairo_pdf_version_t;
 */

// cairo_surface_t * cairo_pdf_surface_create( const char *filename, double width_in_points, double height_in_points );
HB_FUNC( CAIRO_PDF_SURFACE_CREATE )
{
#ifdef CAIRO_HAS_PDF_SURFACE
   hb_cairo_surface_ret( cairo_pdf_surface_create( hb_parc( 1 ), hb_parnd( 2 ), hb_parnd( 3 ) ) );
#else
   hb_retptr( NULL );
#endif
}

// cairo_surface_t * cairo_pdf_surface_create_for_stream( cairo_write_func_t write_func, void *closure, double width_in_points, double height_in_points );

// void cairo_pdf_surface_restrict_to_version( cairo_surface_t *surface, cairo_pdf_version_t version );

// void cairo_pdf_get_versions( cairo_pdf_version_t const **versions, int *num_versions );

// const char * cairo_pdf_version_to_string( cairo_pdf_version_t version );

// void cairo_pdf_surface_set_size( cairo_surface_t *surface, double width_in_points, double height_in_points );
HB_FUNC( CAIRO_PDF_SURFACE_SET_SIZE )
{
#ifdef CAIRO_HAS_PDF_SURFACE
   cairo_surface_t * pSurface = hb_cairo_surface_param( 1 );
   if( pSurface )
      cairo_pdf_surface_set_size( pSurface, hb_parnd( 2 ), hb_parnd( 3 ) );
#else
   /* Just paramter validation */
   hb_cairo_surface_param( 1 );
#endif
}
