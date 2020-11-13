/*
 * Cairo library: svg
 *
 * Copyright 2020 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbcairo.h"

/*
 * enum cairo_svg_version_t; 
 */

// cairo_surface_t * cairo_svg_surface_create( const char *filename, double width_in_points, double height_in_points );
HB_FUNC( CAIRO_SVG_SURFACE_CREATE )
{
#ifdef CAIRO_HAS_SVG_SURFACE
   hb_cairo_surface_ret( cairo_svg_surface_create( hb_parc( 1 ), hb_parnd( 2 ), hb_parnd( 3 ) ) );
#else
   hb_retptr( NULL );
#endif
}

// cairo_surface_t * cairo_svg_surface_create_for_stream( cairo_write_func_t write_func, void *closure, double width_in_points, double height_in_points );

// void cairo_svg_surface_restrict_to_version( cairo_surface_t *surface, cairo_svg_version_t version );

// void cairo_svg_get_versions( cairo_svg_version_t const **versions, int *num_versions );

// const char * cairo_svg_version_to_string( cairo_svg_version_t version );
