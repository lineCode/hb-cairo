/*
 * Cairo library: path
 *
 * Copyright 2020 Rafał Jopek ( rafaljopek at hotmail com )
 *
 * Copyright 2009 Mindaugas Kavaliauskas <dbtopas at dbtopas.lt>
 *
 * Paths
 * Paths — Creating paths and manipulating path data
 *
 * Types and Values
 *
 *         cairo_path_t
 * union   cairo_path_data_t
 * enum    cairo_path_data_type_t
 *
 */

#include "hbcairo.h"

// cairo_path_t * cairo_copy_path( cairo_t *cr );
HB_FUNC( CAIRO_COPY_PATH )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      hb_cairo_path_ret( cairo_copy_path( pCairo ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// cairo_path_t * cairo_copy_path_flat( cairo_t *cr );
HB_FUNC( CAIRO_COPY_PATH_FLAT )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      hb_cairo_path_ret( cairo_copy_path_flat( pCairo ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void cairo_path_destroy( cairo_path_t *path );
/*
 * The function is in the file core.c
 */

// void cairo_append_path( cairo_t *cr, const cairo_path_t *path );
HB_FUNC( CAIRO_APPEND_PATH )
{
   cairo_t *      pCairo = hb_cairo_param( 1 );
   cairo_path_t * pPath  = hb_cairo_path_param( 2 );

   if( pCairo && pPath )
   {
      cairo_append_path( pCairo, pPath );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// cairo_bool_t cairo_has_current_point( cairo_t *cr );
HB_FUNC( CAIRO_HAS_CURRENT_POINT )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      hb_retl( cairo_has_current_point( pCairo ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void cairo_get_current_point( cairo_t *cr, double *x, double *y );
HB_FUNC( CAIRO_GET_CURRENT_POINT )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      PHB_ITEM pItem = hb_stackReturnItem();
      double   x, y;
      hb_arrayNew( pItem, 2 );
      cairo_get_current_point( pCairo, &x, &y );
      hb_arraySetND( pItem, 1, x );
      hb_arraySetND( pItem, 2, y );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void cairo_new_path( cairo_t *cr );
HB_FUNC( CAIRO_NEW_PATH )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      cairo_new_path( pCairo );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void cairo_new_sub_path( cairo_t *cr );

// void cairo_close_path( cairo_t *cr );
HB_FUNC( CAIRO_CLOSE_PATH )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      cairo_close_path( pCairo );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void cairo_arc( cairo_t *cr, double xc, double yc, double radius, double angle1, double angle2 );
HB_FUNC( CAIRO_ARC )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      cairo_arc( pCairo, hb_parnd( 2 ), hb_parnd( 3 ), hb_parnd( 4 ), hb_parnd( 5 ), hb_parnd( 6 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void cairo_arc_negative( cairo_t *cr, double xc, double yc, double radius, double angle1, double angle2 );
HB_FUNC( CAIRO_ARC_NEGATIVE )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      cairo_arc_negative( pCairo, hb_parnd( 2 ), hb_parnd( 3 ), hb_parnd( 4 ), hb_parnd( 5 ), hb_parnd( 6 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void cairo_curve_to( cairo_t *cr, double x1, double y1, double x2, double y2, double x3, double y3 );
HB_FUNC( CAIRO_CURVE_TO )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      cairo_curve_to( pCairo, hb_parnd( 2 ), hb_parnd( 3 ), hb_parnd( 4 ), hb_parnd( 5 ), hb_parnd( 6 ), hb_parnd( 7 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void cairo_line_to( cairo_t *cr, double x, double y );
HB_FUNC( CAIRO_LINE_TO )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      cairo_line_to( pCairo, hb_parnd( 2 ), hb_parnd( 3 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void cairo_move_to( cairo_t *cr, double x, double y );
HB_FUNC( CAIRO_MOVE_TO )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      cairo_move_to( pCairo, hb_parnd( 2 ), hb_parnd( 3 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void cairo_rectangle( cairo_t *cr, double x, double y, double width, double height );
HB_FUNC( CAIRO_RECTANGLE )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      cairo_rectangle( pCairo, hb_parnd( 2 ), hb_parnd( 3 ), hb_parnd( 4 ), hb_parnd( 5 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void cairo_glyph_path( cairo_t *cr, const cairo_glyph_t *glyphs, int num_glyphs );

// void cairo_text_path( cairo_t *cr, const char *utf8 );
HB_FUNC( CAIRO_TEXT_PATH )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      void * hText;
      cairo_text_path( pCairo, hb_parstr_utf8( 2, &hText, NULL ) );
      hb_strfree( hText );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void cairo_rel_curve_to( cairo_t *cr, double dx1, double dy1, double dx2, double dy2, double dx3, double dy3 );
HB_FUNC( CAIRO_REL_CURVE_TO )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      cairo_rel_curve_to( pCairo, hb_parnd( 2 ), hb_parnd( 3 ), hb_parnd( 4 ), hb_parnd( 5 ), hb_parnd( 6 ), hb_parnd( 7 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void cairo_rel_line_to( cairo_t *cr, double dx, double dy );
HB_FUNC( CAIRO_REL_LINE_TO )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      cairo_rel_line_to( pCairo, hb_parnd( 2 ), hb_parnd( 3 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void cairo_rel_move_to( cairo_t *cr, double dx, double dy );
HB_FUNC( CAIRO_REL_MOVE_TO )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      cairo_rel_move_to( pCairo, hb_parnd( 2 ), hb_parnd( 3 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void cairo_path_extents( cairo_t *cr, double *x1, double *y1, double *x2, double *y2 );
HB_FUNC( CAIRO_PATH_EXTENTS )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      PHB_ITEM pItem = hb_stackReturnItem();
      double   x1, y1, x2, y2;

      cairo_path_extents( pCairo, &x1, &y1, &x2, &y2 );
      hb_arrayNew( pItem, 4 );
      hb_arraySetND( pItem, 1, x1 );
      hb_arraySetND( pItem, 2, y1 );
      hb_arraySetND( pItem, 3, x2 );
      hb_arraySetND( pItem, 4, y2 );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}
