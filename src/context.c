/*
 * Cairo library: drawing context
 *
 * Copyright 2020 Rafał Jopek ( rafaljopek at hotmail com )
 *
 * Copyright 2009 Mindaugas Kavaliauskas <dbtopas at dbtopas.lt>
 *
 * cairo_t
 * cairo_t — The cairo drawing context
 *
 * Types and Values
 *
 * typedef   cairo_t
 * enum      cairo_antialias_t
 * enum      cairo_fill_rule_t
 * enum      cairo_line_cap_t
 * enum      cairo_line_join_t
 * enum      cairo_operator_t
 *	          cairo_rectangle_t
 * 	       cairo_rectangle_list_t
 *
 */

#include "hbcairo.h"

// cairo_t * cairo_create( cairo_surface_t *target );
HB_FUNC( CAIRO_CREATE )
{
   cairo_surface_t * pSurface = hb_cairo_surface_param( 1 );

   if( pSurface )
   {
      hb_cairo_ret( cairo_create( pSurface ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// cairo_t * cairo_reference( cairo_t *cr );

// void cairo_destroy( cairo_t *cr );
/*
 * The function is in the file core.c
 */

// cairo_status_t cairo_status( cairo_t *cr );
HB_FUNC( CAIRO_STATUS )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      hb_retni( cairo_status( pCairo ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void cairo_save( cairo_t *cr );
HB_FUNC( CAIRO_SAVE )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      cairo_save( pCairo );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void cairo_restore( cairo_t *cr );
HB_FUNC( CAIRO_RESTORE )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      cairo_restore( pCairo );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// cairo_surface_t * cairo_get_target( cairo_t *cr );

// void cairo_push_group( cairo_t *cr );
HB_FUNC( CAIRO_PUSH_GROUP )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      cairo_push_group( pCairo );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void cairo_push_group_with_content( cairo_t *cr, cairo_content_t content );

// cairo_pattern_t * cairo_pop_group( cairo_t *cr );

// void cairo_pop_group_to_source( cairo_t *cr );
HB_FUNC( CAIRO_POP_GROUP_TO_SOURCE )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      cairo_pop_group_to_source( pCairo );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// cairo_surface_t * cairo_get_group_target( cairo_t *cr );

// void cairo_set_source_rgb( cairo_t *cr, double red, double green, double blue );
HB_FUNC( CAIRO_SET_SOURCE_RGB )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      cairo_set_source_rgb( pCairo, hb_parnd( 2 ), hb_parnd( 3 ), hb_parnd( 4 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void cairo_set_source_rgba( cairo_t *cr, double red, double green, double blue, double alpha );
HB_FUNC( CAIRO_SET_SOURCE_RGBA )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      cairo_set_source_rgba( pCairo, hb_parnd( 2 ), hb_parnd( 3 ), hb_parnd( 4 ), hb_parnd( 5 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void cairo_set_source( cairo_t *cr, cairo_pattern_t *source );
HB_FUNC( CAIRO_SET_SOURCE )
{
   cairo_t * pCairo = hb_cairo_param( 1 );
   cairo_pattern_t * pPattern = hb_cairo_pattern_param( 2 );

   if( pCairo )
   {
      cairo_set_source( pCairo, pPattern );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void cairo_set_source_surface( cairo_t *cr, cairo_surface_t *surface, double x, double y );
HB_FUNC( CAIRO_SET_SOURCE_SURFACE )
{
   cairo_t * pCairo = hb_cairo_param( 1 );
   cairo_surface_t * pSurface = hb_cairo_surface_param( 2 );

   cairo_set_source_surface( pCairo, pSurface, hb_parnd( 3 ), hb_parnd( 4 ) );
}

// cairo_pattern_t * cairo_get_source( cairo_t *cr );

// void cairo_set_antialias( cairo_t *cr, cairo_antialias_t antialias );

// cairo_antialias_t cairo_get_antialias( cairo_t *cr );

// void cairo_set_dash( cairo_t *cr, const double *dashes, int num_dashes, double offset );
HB_FUNC( CAIRO_SET_DASH )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      PHB_ITEM pItem;

      if( ( pItem = hb_param( 2, HB_IT_ARRAY ) ) != NULL )
      {
         int      i, iCount = ( int ) hb_arrayLen( pItem );
         double * pDashes = NULL;

         if( iCount )
            pDashes = ( double * ) hb_xgrab( iCount * sizeof( double ) );

         for( i = 0; i < iCount; i++ )
            pDashes[ i ] = hb_arrayGetND( pItem, ( HB_SIZE ) i + 1 );
         cairo_set_dash( pCairo, pDashes, iCount, hb_parnd( 3 ) );

         if( pDashes )
            hb_xfree( pDashes );
      }
      else
      {
         hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      }
   }
}

// int cairo_get_dash_count( cairo_t *cr );

// void cairo_get_dash( cairo_t *cr, double *dashes, double *offset );
HB_FUNC( CAIRO_GET_DASH )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      PHB_ITEM pItem;
      int      i, iCount;
      double * pDashes, dOffset;

      iCount  = cairo_get_dash_count( pCairo );
      pDashes = ( double * ) hb_xgrab( iCount * sizeof( double ) );
      cairo_get_dash( pCairo, pDashes, &dOffset );
      hb_stornd( dOffset, 3 );

      pItem = hb_itemArrayNew( ( HB_SIZE ) iCount );
      for( i = 0; i < iCount; i++ )
         hb_arraySetND( pItem, ( HB_SIZE ) i + 1, pDashes[ i ] );
      hb_xfree( pDashes );
      hb_itemParamStoreForward( 2, pItem );
      hb_itemRelease( pItem );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }

}

// void cairo_set_fill_rule( cairo_t *cr,cairo_fill_rule_t fill_rule );
HB_FUNC( CAIRO_SET_FILL_RULE )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      cairo_set_fill_rule( pCairo, ( cairo_fill_rule_t ) hb_parni( 2 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// cairo_fill_rule_t cairo_get_fill_rule( cairo_t *cr );

// void cairo_set_line_cap( cairo_t *cr, cairo_line_cap_t line_cap );
HB_FUNC( CAIRO_SET_LINE_CAP )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      cairo_set_line_cap( pCairo, ( cairo_line_cap_t ) hb_parni( 2 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// cairo_line_cap_t cairo_get_line_cap( cairo_t *cr );

// void cairo_set_line_join( cairo_t *cr, cairo_line_join_t line_join );
HB_FUNC( CAIRO_SET_LINE_JOIN )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      cairo_set_line_join( pCairo, ( cairo_line_join_t ) hb_parni( 2 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// cairo_line_join_t cairo_get_line_join( cairo_t *cr );

// void cairo_set_line_width( cairo_t *cr, double width );
HB_FUNC( CAIRO_SET_LINE_WIDTH )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      cairo_set_line_width( pCairo, hb_parnd( 2 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// double cairo_get_line_width( cairo_t *cr );
HB_FUNC( CAIRO_GET_LINE_WIDTH )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      hb_retnd( cairo_get_line_width( pCairo ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void cairo_set_miter_limit( cairo_t *cr, double limit );
HB_FUNC( CAIRO_SET_MITER_LIMIT )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      cairo_set_miter_limit( pCairo, hb_parnd( 2 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// double cairo_get_miter_limit( cairo_t *cr );

// void cairo_set_operator( cairo_t *cr, cairo_operator_t op );
HB_FUNC( CAIRO_SET_OPERATOR )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      cairo_set_operator( pCairo, ( cairo_operator_t ) hb_parni( 2 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// cairo_operator_t cairo_get_operator( cairo_t *cr );

// void cairo_set_tolerance( cairo_t *cr, double tolerance );
HB_FUNC( CAIRO_SET_TOLERANCE )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      cairo_set_tolerance( pCairo, hb_parnd( 2 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// double cairo_get_tolerance( cairo_t *cr );

// void cairo_clip( cairo_t *cr );
HB_FUNC( CAIRO_CLIP )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      cairo_clip( pCairo );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void cairo_clip_preserve( cairo_t *cr );
HB_FUNC( CAIRO_CLIP_PRESERVE )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      cairo_clip_preserve( pCairo );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void cairo_clip_extents( cairo_t *cr, double *x1, double *y1, double *x2, double *y2 );
HB_FUNC( CAIRO_CLIP_EXTENTS )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      PHB_ITEM pItem = hb_stackReturnItem();
      double   x1, y1, x2, y2;

      cairo_clip_extents( pCairo, &x1, &y1, &x2, &y2 );
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

// cairo_bool_t cairo_in_clip( cairo_t *cr, double x, double y );

// void cairo_reset_clip( cairo_t *cr );
HB_FUNC( CAIRO_RESET_CLIP )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      cairo_reset_clip( pCairo );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void cairo_rectangle_list_destroy( cairo_rectangle_list_t *rectangle_list );

// cairo_rectangle_list_t * cairo_copy_clip_rectangle_list( cairo_t *cr );

// void cairo_fill( cairo_t *cr );
HB_FUNC( CAIRO_FILL )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      cairo_fill( pCairo );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void cairo_fill_preserve( cairo_t *cr );
HB_FUNC( CAIRO_FILL_PRESERVE )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      cairo_fill_preserve( pCairo );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void cairo_fill_extents( cairo_t *cr, double *x1, double *y1, double *x2, double *y2 );
HB_FUNC( CAIRO_FILL_EXTENTS )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      PHB_ITEM pItem = hb_stackReturnItem();
      double   x1, y1, x2, y2;

      cairo_fill_extents( pCairo, &x1, &y1, &x2, &y2 );
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

// cairo_bool_t cairo_in_fill( cairo_t *cr, double x, double y );
HB_FUNC( CAIRO_IN_FILL )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      hb_retl( cairo_in_fill( pCairo, hb_parnd( 2 ), hb_parnd( 3 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void cairo_mask( cairo_t *cr, cairo_pattern_t *pattern );

// void cairo_mask_surface( cairo_t *cr, cairo_surface_t *surface, double surface_x, double surface_y );

// void cairo_paint( cairo_t *cr );
HB_FUNC( CAIRO_PAINT )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      cairo_paint( pCairo );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void cairo_paint_with_alpha( cairo_t *cr, double alpha );
HB_FUNC( CAIRO_PAINT_WITH_ALPHA )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      cairo_paint_with_alpha( pCairo, hb_parnd( 2 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void cairo_stroke( cairo_t *cr );
HB_FUNC( CAIRO_STROKE )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      cairo_stroke( pCairo );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void cairo_stroke_preserve( cairo_t *cr );
HB_FUNC( CAIRO_STROKE_PRESERVE )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      cairo_stroke_preserve( pCairo );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void cairo_stroke_extents( cairo_t *cr, double *x1, double *y1, double *x2, double *y2 );
HB_FUNC( CAIRO_STROKE_EXTENTS )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      PHB_ITEM pItem = hb_stackReturnItem();
      double   x1, y1, x2, y2;

      cairo_stroke_extents( pCairo, &x1, &y1, &x2, &y2 );
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
// cairo_bool_t cairo_in_stroke( cairo_t *cr, double x, double y );
HB_FUNC( CAIRO_IN_STROKE )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      hb_retl( cairo_in_stroke( pCairo, hb_parnd( 2 ), hb_parnd( 3 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void cairo_copy_page( cairo_t *cr );
HB_FUNC( CAIRO_COPY_PAGE )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      cairo_copy_page( pCairo );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void cairo_show_page( cairo_t *cr );
HB_FUNC( CAIRO_SHOW_PAGE )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      cairo_show_page( pCairo );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}
// unsigned int cairo_get_reference_count( cairo_t *cr );

// cairo_status_t cairo_set_user_data( cairo_t *cr, const cairo_user_data_key_t *key, void *user_data, cairo_destroy_func_t destroy );

// void * cairo_get_user_data( cairo_t *cr, const cairo_user_data_key_t *key );
