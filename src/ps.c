/*
 * Cairo library: ps
 *
 * Copyright 2011 Mindaugas Kavaliauskas <dbtopas at dbtopas.lt>
 *
 */

#include "hbcairo.h"

HB_FUNC( CAIRO_PS_SURFACE_CREATE )
{
#ifdef CAIRO_HAS_PS_SURFACE
   hb_cairo_surface_ret( cairo_ps_surface_create( hb_parc( 1 ), hb_parnd( 2 ), hb_parnd( 3 ) ) );
#else
   hb_retptr( NULL );
#endif
}

HB_FUNC( CAIRO_PS_SURFACE_SET_SIZE )
{
#ifdef CAIRO_HAS_PS_SURFACE
   cairo_surface_t * pSurface = hb_cairo_surface_param( 1 );
   if( pSurface )
      cairo_ps_surface_set_size( pSurface, hb_parnd( 2 ), hb_parnd( 3 ) );
#else
   /* Parameter validation */
   hb_cairo_surface_param( 1 );
#endif
}

HB_FUNC( CAIRO_PS_SURFACE_SET_EPS )
{
#ifdef CAIRO_HAS_PS_SURFACE
   cairo_surface_t * pSurface = hb_cairo_surface_param( 1 );
   if( pSurface )
      cairo_ps_surface_set_eps( pSurface, hb_parl( 2 ) );
#else
   /* Parameter validation */
   hb_cairo_surface_param( 1 );
#endif
}

HB_FUNC( CAIRO_PS_SURFACE_GET_EPS )
{
#ifdef CAIRO_HAS_PS_SURFACE
   cairo_surface_t * pSurface = hb_cairo_surface_param( 1 );
   if( pSurface )
      hb_retl( cairo_ps_surface_get_eps( pSurface ) );
#else
   /* Parameter validation */
   hb_cairo_surface_param( 1 );
#endif
}
