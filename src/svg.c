/*
 * Cairo library: svg
 *
 * Copyright 2020 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbcairo.h"

HB_FUNC( CAIRO_SVG_SURFACE_CREATE )
{
#ifdef CAIRO_HAS_SVG_SURFACE
   hb_cairo_surface_ret( cairo_svg_surface_create( hb_parc( 1 ), hb_parnd( 2 ), hb_parnd( 3 ) ) );
#else
   hb_retptr( NULL );
#endif
}
