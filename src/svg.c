/*
 * Cairo library: svg
 *
 * Copyright 2020 Rafał Jopek ( rafaljopek at hotmail com )
 *
 * SVG Surfaces — Rendering SVG documents
 *
 * Types and Values
 *
 * #define	CAIRO_HAS_SVG_SURFACE
 * enum	   cairo_svg_version_t
 * enum	   cairo_svg_unit_t
 *
 */

#include "hbcairo.h"

// cairo_surface_t *cairo_svg_surface_create( const char *filename, double width_in_points, double height_in_points );
HB_FUNC( CAIRO_SVG_SURFACE_CREATE )
{
#ifdef CAIRO_HAS_SVG_SURFACE

   if( hb_param( 1, HB_IT_STRING ) != NULL && hb_param( 2, HB_IT_DOUBLE ) != NULL && hb_param( 3, HB_IT_DOUBLE ) != NULL  )
   {
      hb_cairo_surface_ret( cairo_svg_surface_create( hb_parc( 1 ), hb_parnd( 2 ), hb_parnd( 3 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }

#else
   hb_retptr( NULL );
#endif
}

// cairo_surface_t *cairo_svg_surface_create_for_stream( cairo_write_func_t write_func, void *closure, double width_in_points, double height_in_points );
HB_FUNC( CAIRO_SVG_SURFACE_CREATE_FOR_STREAM )
{
}

// cairo_svg_unit_t cairo_svg_surface_get_document_unit( cairo_surface_t *surface );
HB_FUNC( CAIRO_SVG_SURFACE_GET_DOCUMENT_UNIT )
{
#ifdef CAIRO_HAS_SVG_SURFACE

   cairo_surface_t * pSurface = hb_cairo_surface_param( 1 );

   if( pSurface )
   {
      hb_retni( cairo_svg_surface_get_document_unit( pSurface ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }

#else
   /* Parameter validation */
   hb_cairo_surface_param( 1 );
#endif
}

// void cairo_svg_surface_set_document_unit( cairo_surface_t *surface, cairo_svg_unit_t unit );
HB_FUNC( CAIRO_SVG_SURFACE_SET_DOCUMENT_UNIT )
{
#ifdef CAIRO_HAS_SVG_SURFACE

   cairo_surface_t * pSurface = hb_cairo_surface_param( 1 );

   if( pSurface && hb_param( 2, HB_IT_INTEGER ) != NULL )
   {
      cairo_svg_surface_set_document_unit( pSurface, ( cairo_svg_unit_t ) hb_parni( 2 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }

#else
   /* Parameter validation */
   hb_cairo_surface_param( 1 );
#endif
}

// void cairo_svg_surface_restrict_to_version( cairo_surface_t *surface, cairo_svg_version_t version );
HB_FUNC( CAIRO_SVG_SURFACE_RESTRICT_TO_VERSION )
{
#ifdef CAIRO_HAS_SVG_SURFACE

   cairo_surface_t * pSurface = hb_cairo_surface_param( 1 );

   if( pSurface && hb_param( 2, HB_IT_INTEGER ) != NULL )
   {
      cairo_svg_surface_restrict_to_version( pSurface, ( cairo_svg_version_t ) hb_parni( 2 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }

#else
   /* Parameter validation */
   hb_cairo_surface_param( 1 );
#endif
}

// void cairo_svg_get_versions( cairo_svg_version_t const **versions, int *num_versions );
HB_FUNC( CAIRO_SVG_GET_VERSIONS )
{
}

// const char *cairo_svg_version_to_string( cairo_svg_version_t version );
HB_FUNC( CAIRO_SVG_VERSION_TO_STRING )
{
#ifdef CAIRO_HAS_SVG_SURFACE

   if( hb_param( 1, HB_IT_INTEGER ) != NULL )
   {
      hb_retc( cairo_svg_version_to_string( ( cairo_svg_version_t ) hb_parni( 1 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }

#else
   hb_ret( NULL );
#endif
}
