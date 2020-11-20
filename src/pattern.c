/*
 * Cairo library: pattern
 *
 * Copyright 2020 Rafał Jopek ( rafaljopek at hotmail com )
 *
 * Copyright 2013 Oscar Hernandez Suarez <oscar.hernandez.suarez@gmail.com>
 *
 * cairo_pattern_t
 * cairo_pattern_t — Sources for drawing
 *
 * Types and Values
 *
 * typedef   cairo_pattern_t
 *    enum   cairo_extend_t
 *    enum   cairo_filter_t
 *    enum   cairo_pattern_type_t
 *
 */

#include "hbcairo.h"

// void cairo_pattern_add_color_stop_rgb( cairo_pattern_t *pattern, double offset, double red, double green, double blue );
HB_FUNC( CAIRO_PATTERN_ADD_COLOR_STOP_RGB )
{
   cairo_pattern_t * pPattern = hb_cairo_pattern_param( 1 );

   if( pPattern )
   {
      cairo_pattern_add_color_stop_rgb( pPattern, hb_parnd( 2 ), hb_parnd( 3 ), hb_parnd( 4 ), hb_parnd( 5 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void cairo_pattern_add_color_stop_rgba( cairo_pattern_t *pattern, double offset, double red, double green, double blue, double alpha );
HB_FUNC( CAIRO_PATTERN_ADD_COLOR_STOP_RGBA )
{
   cairo_pattern_t * pPattern = hb_cairo_pattern_param( 1 );

   if( pPattern )
   {
      cairo_pattern_add_color_stop_rgba( pPattern, hb_parnd( 2 ), hb_parnd( 3 ), hb_parnd( 4 ), hb_parnd( 5 ), hb_parnd( 6 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// cairo_status_t cairo_pattern_get_color_stop_count( cairo_pattern_t *pattern, int *count );
HB_FUNC( CAIRO_PATTERN_GET_COLOR_STOP_COUNT )
{
   cairo_pattern_t * pPattern = hb_cairo_pattern_param( 1 );

   if( pPattern )
   {
      int iCount;

      hb_retni( cairo_pattern_get_color_stop_count( pPattern, &iCount ) );
      hb_storni( iCount, 2 );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      hb_cairo_pattern_param( 1 ); /* Parameter validation */
      hb_retni( -1 );              /* There is no good CAIRO_STATUS_* for this */
   }
}

// cairo_status_t cairo_pattern_get_color_stop_rgba( cairo_pattern_t *pattern, int index, double *offset, double *red, double *green, double *blue, double *alpha );
HB_FUNC( CAIRO_PATTERN_GET_COLOR_STOP_RGBA )
{
   cairo_pattern_t * pPattern = hb_cairo_pattern_param( 1 );

   if( pPattern )
   {
      double dOffset;
      double dRed;
      double dGreen;
      double dBlue;
      double dAlpha;

      hb_retni( cairo_pattern_get_color_stop_rgba( pPattern, hb_parni( 2 ), &dOffset, &dRed, &dGreen, &dBlue, &dAlpha ) );

      hb_stornd( dOffset, 3 );
      hb_stornd( dRed, 4 );
      hb_stornd( dGreen, 5 );
      hb_stornd( dBlue, 6 );
      hb_stornd( dAlpha, 7 );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      hb_cairo_pattern_param( 1 ); /* Parameter validation */
      hb_retni( -1 );              /* There is no good CAIRO_STATUS_* for this */
   }
}

// cairo_pattern_t *cairo_pattern_create_rgb( double red, double green, double blue );
HB_FUNC( CAIRO_PATTERN_CREATE_RGB )
{
   hb_cairo_pattern_ret( cairo_pattern_create_rgb( hb_parnd( 1 ), hb_parnd( 2 ), hb_parnd( 3 ) ) );
}

// cairo_pattern_t *cairo_pattern_create_rgba( double red, double green, double blue, double alpha );
HB_FUNC( CAIRO_PATTERN_CREATE_RGBA )
{
   hb_cairo_pattern_ret( cairo_pattern_create_rgba( hb_parnd( 1 ), hb_parnd( 2 ), hb_parnd( 3 ), hb_parnd( 3 ) ) );
}

// cairo_status_t cairo_pattern_get_rgba( cairo_pattern_t *pattern, double *red, double *green, double *blue, double *alpha );
HB_FUNC( CAIRO_PATTERN_GET_RGBA )
{
   cairo_pattern_t * pPattern = hb_cairo_pattern_param( 1 );

   if( pPattern )
   {
      double dRed;
      double dGreen;
      double dBlue;
      double dAlpha;

      hb_retni( cairo_pattern_get_rgba( pPattern, &dRed, &dGreen, &dBlue, &dAlpha ) );

      hb_stornd( dRed, 2 );
      hb_stornd( dGreen, 3 );
      hb_stornd( dBlue, 4 );
      hb_stornd( dAlpha, 5 );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      hb_cairo_pattern_param( 1 ); /* Parameter validation */
      hb_retni( -1 );              /* There is no good CAIRO_STATUS_* for this */
   }
}

// cairo_pattern_t *cairo_pattern_create_for_surface( cairo_surface_t *surface );
HB_FUNC( CAIRO_PATTERN_CREATE_FOR_SURFACE )
{
   hb_cairo_pattern_ret( cairo_pattern_create_for_surface( hb_cairo_surface_param( 1 ) ) );
}

// cairo_status_t cairo_pattern_get_surface( cairo_pattern_t *pattern, cairo_surface_t **surface );
HB_FUNC( CAIRO_PATTERN_GET_SURFACE )
{
   cairo_pattern_t * pPattern = hb_cairo_pattern_param( 1 );

   if( pPattern )
   {
      cairo_surface_t * pSurface;

      hb_retni( cairo_pattern_get_surface( pPattern, &pSurface ) );

      hb_cairoSurfaceStor( pSurface, 2 );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      hb_cairo_pattern_param( 1 ); /* Parameter validation */
      hb_retni( -1 );              /* There is no good CAIRO_STATUS_* for this */
   }
}

// cairo_pattern_t *cairo_pattern_create_linear( double x0, double y0, double x1, double y1 );
HB_FUNC( CAIRO_PATTERN_CREATE_LINEAR )
{
   hb_cairo_pattern_ret( cairo_pattern_create_linear( hb_parnd( 1 ), hb_parnd( 2 ), hb_parnd( 3 ), hb_parnd( 4 ) ) );
}

// cairo_status_t cairo_pattern_get_linear_points( cairo_pattern_t *pattern, double *x0, double *y0, double *x1, double *y1 );
HB_FUNC( CAIRO_PATTERN_GET_LINEAR_POINTS )
{
   cairo_pattern_t * pPattern = hb_cairo_pattern_param( 1 );

   if( pPattern )
   {
      double dX0;
      double dY0;
      double dX1;
      double dY1;

      hb_retni( cairo_pattern_get_linear_points( pPattern, &dX0, &dY0, &dX1, &dY1 ) );

      hb_stornd( dX0, 2 );
      hb_stornd( dY0, 3 );
      hb_stornd( dX1, 4 );
      hb_stornd( dY1, 5 );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      hb_cairo_pattern_param( 1 ); /* Parameter validation */
      hb_retni( -1 );              /* There is no good CAIRO_STATUS_* for this */
   }
}

// cairo_pattern_t *cairo_pattern_create_radial( double cx0, double cy0, double radius0, double cx1, double cy1, double radius1 );
HB_FUNC( CAIRO_PATTERN_CREATE_RADIAL )
{
   hb_cairo_pattern_ret( cairo_pattern_create_radial( hb_parnd( 1 ), hb_parnd( 2 ), hb_parnd( 3 ), hb_parnd( 4 ), hb_parnd( 5 ), hb_parnd( 6 ) ) );
}

// cairo_status_t cairo_pattern_get_radial_circles( cairo_pattern_t *pattern, double *x0, double *y0, double *r0, double *x1, double *y1, double *r1 );
HB_FUNC( CAIRO_PATTERN_GET_RADIAL_CIRCLES )
{
   cairo_pattern_t * pPattern = hb_cairo_pattern_param( 1 );

   if( pPattern )
   {
      double dX0;
      double dY0;
      double dR0;
      double dX1;
      double dY1;
      double dR1;

      hb_retni( cairo_pattern_get_radial_circles( pPattern, &dX0, &dY0, &dR0, &dX1, &dY1, &dR1 ) );

      hb_stornd( dX0, 2 );
      hb_stornd( dY0, 3 );
      hb_stornd( dR0, 4 );
      hb_stornd( dX1, 5 );
      hb_stornd( dY1, 6 );
      hb_stornd( dR1, 7 );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      hb_cairo_pattern_param( 1 ); /* Parameter validation */
      hb_retni( -1 );              /* There is no good CAIRO_STATUS_* for this */
   }
}

// cairo_pattern_t *cairo_pattern_create_mesh(  void  );

// void cairo_mesh_pattern_begin_patch(  cairo_pattern_t *pattern  );

// void cairo_mesh_pattern_end_patch( cairo_pattern_t *pattern );

// void cairo_mesh_pattern_move_to( cairo_pattern_t *pattern, double x, double y );

// void cairo_mesh_pattern_line_to( cairo_pattern_t *pattern, double x, double y );

// void cairo_mesh_pattern_curve_to( cairo_pattern_t *pattern, double x1, double y1, double x2, double y2, double x3, double y3 );

// void cairo_mesh_pattern_set_control_point( cairo_pattern_t *pattern, unsigned int point_num, double x, double y );

// void cairo_mesh_pattern_set_corner_color_rgb( cairo_pattern_t *pattern, unsigned int corner_num, double red, double green, double blue );

// void cairo_mesh_pattern_set_corner_color_rgba( cairo_pattern_t *pattern, unsigned int corner_num, double red, double green, double blue, double alpha );

// cairo_status_t cairo_mesh_pattern_get_patch_count( cairo_pattern_t *pattern, unsigned int *count );

// cairo_path_t *cairo_mesh_pattern_get_path( cairo_pattern_t *pattern, unsigned int patch_num );

// cairo_status_t cairo_mesh_pattern_get_control_point(  cairo_pattern_t *pattern, unsigned int patch_num, unsigned int point_num, double *x, double *y );

// cairo_status_t cairo_mesh_pattern_get_corner_color_rgba( cairo_pattern_t *pattern, unsigned int patch_num, unsigned int corner_num, double *red, double *green, double *blue, double *alpha );

// cairo_pattern_t *cairo_pattern_reference( cairo_pattern_t *pattern );

// void cairo_pattern_destroy( cairo_pattern_t *pattern );

// cairo_status_t cairo_pattern_status( cairo_pattern_t *pattern );
HB_FUNC( CAIRO_PATTERN_STATUS )
{
   cairo_pattern_t * pPattern = hb_cairo_pattern_param( 1 );

   if( pPattern )
   {
      hb_retni( cairo_pattern_status( pPattern ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      hb_cairo_pattern_param( 1 ); /* Parameter validation */
      hb_retni( -1 );
   }
}

// void cairo_pattern_set_extend( cairo_pattern_t *pattern, cairo_extend_t extend );

// cairo_extend_t cairo_pattern_get_extend( cairo_pattern_t *pattern );

// void cairo_pattern_set_filter( cairo_pattern_t *pattern, cairo_filter_t filter );

// cairo_filter_t cairo_pattern_get_filter( cairo_pattern_t *pattern );

// void cairo_pattern_set_matrix( cairo_pattern_t *pattern, const cairo_matrix_t *matrix );

// void cairo_pattern_get_matrix( cairo_pattern_t *pattern, cairo_matrix_t *matrix );

// cairo_pattern_type_t cairo_pattern_get_type( cairo_pattern_t *pattern );

// unsigned int cairo_pattern_get_reference_count( cairo_pattern_t *pattern );

// cairo_status_t cairo_pattern_set_user_data( cairo_pattern_t *pattern, const cairo_user_data_key_t *key, void *user_data, cairo_destroy_func_t destroy );

// void *cairo_pattern_get_user_data( cairo_pattern_t *pattern, const cairo_user_data_key_t *key );
