/*
 * Cairo library: transformations
 *
 * Copyright 2020 Rafał Jopek ( rafaljopek at hotmail com )
 *
 * Copyright 2009 Mindaugas Kavaliauskas <dbtopas at dbtopas.lt>
 *
 * Transformations
 * Transformations — Manipulating the current transformation matrix
 *
 */

#include "hbcairo.h"

// void cairo_translate( cairo_t *cr, double tx, double ty );
HB_FUNC( CAIRO_TRANSLATE )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      cairo_translate( pCairo, hb_parnd( 2 ), hb_parnd( 3 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void cairo_scale( cairo_t *cr, double sx, double sy );
HB_FUNC( CAIRO_SCALE )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      cairo_scale( pCairo, hb_parnd( 2 ), hb_parnd( 3 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void cairo_rotate( cairo_t *cr, double angle );
HB_FUNC( CAIRO_ROTATE )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      cairo_rotate( pCairo, hb_parnd( 2 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void cairo_transform( cairo_t *cr, const cairo_matrix_t *matrix );
HB_FUNC( CAIRO_TRANSFORM )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      PHB_ITEM pItem;
      if( ( pItem = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 6 )
      {
         cairo_matrix_t m;

         m.xx = hb_arrayGetND( pItem, 1 );
         m.yx = hb_arrayGetND( pItem, 2 );
         m.xy = hb_arrayGetND( pItem, 3 );
         m.yy = hb_arrayGetND( pItem, 4 );
         m.x0 = hb_arrayGetND( pItem, 5 );
         m.y0 = hb_arrayGetND( pItem, 6 );
         cairo_transform( pCairo, &m );
      }
      else
      {
         hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      }
   }
}

// void cairo_set_matrix( cairo_t *cr, const cairo_matrix_t *matrix );
HB_FUNC( CAIRO_SET_MATRIX )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      PHB_ITEM pItem;
      if( ( pItem = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 6 )
      {
         cairo_matrix_t m;

         m.xx = hb_arrayGetND( pItem, 1 );
         m.yx = hb_arrayGetND( pItem, 2 );
         m.xy = hb_arrayGetND( pItem, 3 );
         m.yy = hb_arrayGetND( pItem, 4 );
         m.x0 = hb_arrayGetND( pItem, 5 );
         m.y0 = hb_arrayGetND( pItem, 6 );
         cairo_set_matrix( pCairo, &m );
      }
      else
      {
         hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      }
   }
}

// void cairo_get_matrix( cairo_t *cr, cairo_matrix_t *matrix );
HB_FUNC( CAIRO_GET_MATRIX )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      PHB_ITEM       pItem = hb_stackReturnItem();
      cairo_matrix_t m;

      cairo_get_matrix( pCairo, &m );
      hb_arrayNew( pItem, 6 );
      hb_arraySetND( pItem, 1, m.xx );
      hb_arraySetND( pItem, 2, m.yx );
      hb_arraySetND( pItem, 3, m.xy );
      hb_arraySetND( pItem, 4, m.yy );
      hb_arraySetND( pItem, 5, m.x0 );
      hb_arraySetND( pItem, 6, m.y0 );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void cairo_identity_matrix( cairo_t *cr );
HB_FUNC( CAIRO_IDENTITY_MATRIX )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      cairo_identity_matrix( pCairo );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void cairo_user_to_device( cairo_t *cr, double *x, double *y );

// void cairo_user_to_device_distance( cairo_t *cr, double *dx, double *dy );

// void cairo_device_to_user( cairo_t *cr, double *x, double *y );

// void cairo_device_to_user_distance( cairo_t *cr, double *dx, double *dy );
