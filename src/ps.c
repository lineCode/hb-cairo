/*
 * Cairo library: ps
 *
 * Copyright 2020 Rafał Jopek ( rafaljopek at hotmail com )
 *
 * Copyright 2011 Mindaugas Kavaliauskas <dbtopas at dbtopas.lt>
 *
 * PostScript Surfaces — Rendering PostScript documents
 *
 * Types and Values
 *
 * #define  CAIRO_HAS_PS_SURFACE
 * enum     cairo_ps_level_t
 *
 */

#include "hbcairo.h"

// cairo_surface_t *cairo_ps_surface_create( const char *filename, double width_in_points, double height_in_points );
HB_FUNC( CAIRO_PS_SURFACE_CREATE )
{
#ifdef CAIRO_HAS_PS_SURFACE

   if( hb_param( 1, HB_IT_STRING ) != NULL && hb_param( 2, HB_IT_DOUBLE ) != NULL && hb_param( 3, HB_IT_DOUBLE ) != NULL  )
   {
      hb_cairo_surface_ret( cairo_ps_surface_create( hb_parc( 1 ), hb_parnd( 2 ), hb_parnd( 3 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }

#else
   hb_retptr( NULL );
#endif
}

// cairo_surface_t *cairo_ps_surface_create_for_stream( cairo_write_func_t write_func, void *closure, double width_in_points, double height_in_points );
HB_FUNC( CAIRO_PS_SURFACE_CREATE_FOR_STREAM )
{
}

// void cairo_ps_surface_restrict_to_level( cairo_surface_t *surface, cairo_ps_level_t level );
HB_FUNC( CAIRO_PS_SURFACE_RESTRICT_TO_LEVEL )
{
#ifdef CAIRO_HAS_PS_SURFACE

   cairo_surface_t * pSurface = hb_cairo_surface_param( 1 );

   if( pSurface && hb_param( 2, HB_IT_INTEGER ) != NULL )
   {
      cairo_ps_surface_restrict_to_level( pSurface, ( cairo_ps_level_t ) hb_parni( 2 ) );
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

// void cairo_ps_get_levels( cairo_ps_level_t const **levels, int *num_levels );
HB_FUNC( CAIRO_PS_GET_LEVELS )
{
}

// const char *cairo_ps_level_to_string( cairo_ps_level_t level );
HB_FUNC( CAIRO_PS_LEVEL_TO_STRING )
{
#ifdef CAIRO_HAS_PS_SURFACE

   if( hb_param( 1, HB_IT_INTEGER ) != NULL )
   {
      hb_retc( cairo_ps_level_to_string( ( cairo_ps_level_t ) hb_parni( 1 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }

#else
   hb_ret( NULL );
#endif
}

// void cairo_ps_surface_set_eps( cairo_surface_t *surface, cairo_bool_t eps );
HB_FUNC( CAIRO_PS_SURFACE_SET_EPS )
{
#ifdef CAIRO_HAS_PS_SURFACE

   cairo_surface_t * pSurface = hb_cairo_surface_param( 1 );

   if( pSurface && hb_param( 2, HB_IT_LOGICAL ) != NULL )
   {
      cairo_ps_surface_set_eps( pSurface, hb_parl( 2 ) );
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

// cairo_bool_t cairo_ps_surface_get_eps( cairo_surface_t *surface );
HB_FUNC( CAIRO_PS_SURFACE_GET_EPS )
{
#ifdef CAIRO_HAS_PS_SURFACE

   cairo_surface_t * pSurface = hb_cairo_surface_param( 1 );

   if( pSurface )
   {
      hb_retl( cairo_ps_surface_get_eps( pSurface ) );
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

// void cairo_ps_surface_set_size( cairo_surface_t *surface, double width_in_points, double height_in_points );
HB_FUNC( CAIRO_PS_SURFACE_SET_SIZE )
{
#ifdef CAIRO_HAS_PS_SURFACE

   cairo_surface_t * pSurface = hb_cairo_surface_param( 1 );

   if( pSurface && hb_param( 2, HB_IT_DOUBLE ) != NULL && hb_param( 3, HB_IT_DOUBLE ) != NULL)
   {
      cairo_ps_surface_set_size( pSurface, hb_parnd( 2 ), hb_parnd( 3 ) );
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

// void cairo_ps_surface_dsc_begin_setup( cairo_surface_t *surface );
HB_FUNC( CAIRO_PS_SURFACE_DSC_BEGIN_SETUP )
{
#ifdef CAIRO_HAS_PS_SURFACE

   cairo_surface_t * pSurface = hb_cairo_surface_param( 1 );
   if( pSurface )
   {
      cairo_ps_surface_dsc_begin_setup( pSurface );
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

// void cairo_ps_surface_dsc_begin_page_setup( cairo_surface_t *surface );
HB_FUNC( CAIRO_PS_SURFACE_DSC_BEGIN_PAGE_SETUP )
{
#ifdef CAIRO_HAS_PS_SURFACE

   cairo_surface_t * pSurface = hb_cairo_surface_param( 1 );

   if( pSurface )
   {
      cairo_ps_surface_dsc_begin_page_setup( pSurface );
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

// void cairo_ps_surface_dsc_comment( cairo_surface_t *surface, const char *comment );
HB_FUNC( CAIRO_PS_SURFACE_DSC_COMMENT )
{
#ifdef CAIRO_HAS_PS_SURFACE

   cairo_surface_t * pSurface = hb_cairo_surface_param( 1 );

   if( pSurface && hb_param( 2, HB_IT_STRING ) != NULL )
   {
      cairo_ps_surface_dsc_comment( pSurface, hb_parc( 2 ) );
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

