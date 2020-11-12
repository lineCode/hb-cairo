/*
 * Cairo library: path
 *
 * Copyright 2009 Mindaugas Kavaliauskas <dbtopas at dbtopas.lt>
 *
 */

#include "hbcairo.h"

HB_FUNC( CAIRO_APPEND_PATH )
{
   cairo_t *      pCairo = hb_cairo_param( 1 );
   cairo_path_t * pPath  = hb_cairo_path_param( 2 );

   if( pCairo && pPath )
      cairo_append_path( pCairo, pPath );
}

HB_FUNC( CAIRO_ARC )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
      cairo_arc( pCairo, hb_parnd( 2 ), hb_parnd( 3 ), hb_parnd( 4 ), hb_parnd( 5 ), hb_parnd( 6 ) );
}

HB_FUNC( CAIRO_ARC_NEGATIVE )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
      cairo_arc_negative( pCairo, hb_parnd( 2 ), hb_parnd( 3 ), hb_parnd( 4 ), hb_parnd( 5 ), hb_parnd( 6 ) );
}

HB_FUNC( CAIRO_CLOSE_PATH )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
      cairo_close_path( pCairo );
}

HB_FUNC( CAIRO_COPY_PATH )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
      hb_cairo_path_ret( cairo_copy_path( pCairo ) );
}

HB_FUNC( CAIRO_COPY_PATH_FLAT )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
      hb_cairo_path_ret( cairo_copy_path_flat( pCairo ) );
}

HB_FUNC( CAIRO_CURVE_TO )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
      cairo_curve_to( pCairo, hb_parnd( 2 ), hb_parnd( 3 ), hb_parnd( 4 ), hb_parnd( 5 ), hb_parnd( 6 ), hb_parnd( 7 ) );
}

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
}

HB_FUNC( CAIRO_HAS_CURRENT_POINT )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      hb_retl( cairo_has_current_point( pCairo ) );
   }
}

HB_FUNC( CAIRO_LINE_TO )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
      cairo_line_to( pCairo, hb_parnd( 2 ), hb_parnd( 3 ) );
}

HB_FUNC( CAIRO_MOVE_TO )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
      cairo_move_to( pCairo, hb_parnd( 2 ), hb_parnd( 3 ) );
}

HB_FUNC( CAIRO_NEW_PATH )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
      cairo_new_path( pCairo );
}

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
}

HB_FUNC( CAIRO_RECTANGLE )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
      cairo_rectangle( pCairo, hb_parnd( 2 ), hb_parnd( 3 ), hb_parnd( 4 ), hb_parnd( 5 ) );
}

HB_FUNC( CAIRO_REL_CURVE_TO )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
      cairo_rel_curve_to( pCairo, hb_parnd( 2 ), hb_parnd( 3 ), hb_parnd( 4 ), hb_parnd( 5 ), hb_parnd( 6 ), hb_parnd( 7 ) );
}

HB_FUNC( CAIRO_REL_LINE_TO )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
      cairo_rel_line_to( pCairo, hb_parnd( 2 ), hb_parnd( 3 ) );
}

HB_FUNC( CAIRO_REL_MOVE_TO )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
      cairo_rel_move_to( pCairo, hb_parnd( 2 ), hb_parnd( 3 ) );
}

HB_FUNC( CAIRO_TEXT_PATH )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      void * hText;
      cairo_text_path( pCairo, hb_parstr_utf8( 2, &hText, NULL ) );
      hb_strfree( hText );
   }
}
