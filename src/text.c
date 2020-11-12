/*
 * Cairo library: text
 *
 * Copyright 2009 Mindaugas Kavaliauskas <dbtopas at dbtopas.lt>
 *
 */

#include "hbcairo.h"

HB_FUNC( CAIRO_FONT_EXTENTS )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      PHB_ITEM pItem = hb_stackReturnItem();
      cairo_font_extents_t fe;

      cairo_font_extents( pCairo, &fe );
      hb_arrayNew( pItem, 5 );
      hb_arraySetND( pItem, 1, fe.ascent        );
      hb_arraySetND( pItem, 2, fe.descent       );
      hb_arraySetND( pItem, 3, fe.height        );
      hb_arraySetND( pItem, 4, fe.max_x_advance );
      hb_arraySetND( pItem, 5, fe.max_y_advance );
   }
}

HB_FUNC( CAIRO_GET_FONT_MATRIX )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      PHB_ITEM       pItem = hb_stackReturnItem();
      cairo_matrix_t m;

      cairo_get_font_matrix( pCairo, &m );
      hb_arrayNew( pItem, 6 );
      hb_arraySetND( pItem, 1, m.xx );
      hb_arraySetND( pItem, 2, m.yx );
      hb_arraySetND( pItem, 3, m.xy );
      hb_arraySetND( pItem, 4, m.yy );
      hb_arraySetND( pItem, 5, m.x0 );
      hb_arraySetND( pItem, 6, m.y0 );
   }
}

HB_FUNC( CAIRO_SELECT_FONT_FACE )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      void * hFamily;
      cairo_select_font_face( pCairo, hb_parstr_utf8( 2, &hFamily, NULL ), ( cairo_font_slant_t ) hb_parni( 3 ), ( cairo_font_weight_t ) hb_parni( 4 ) );
      hb_strfree( hFamily );
   }
}

HB_FUNC( CAIRO_SET_FONT_MATRIX )
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
         cairo_set_font_matrix( pCairo, &m );
      }
      else
         hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

HB_FUNC( CAIRO_SET_FONT_SIZE )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
      cairo_set_font_size( pCairo, hb_parnd( 2 ) );
}

HB_FUNC( CAIRO_SHOW_TEXT )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      void * hText;
      cairo_show_text( pCairo, hb_parstr_utf8( 2, &hText, NULL ) );
      hb_strfree( hText );
   }
}

HB_FUNC( CAIRO_TEXT_EXTENTS )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      void *   hText;
      PHB_ITEM pItem = hb_stackReturnItem();
      cairo_text_extents_t te;

      cairo_text_extents( pCairo, hb_parstr_utf8( 2, &hText, NULL ), &te );
      hb_strfree( hText );
      hb_arrayNew( pItem, 6 );
      hb_arraySetND( pItem, 1, te.x_bearing );
      hb_arraySetND( pItem, 2, te.y_bearing );
      hb_arraySetND( pItem, 3, te.width     );
      hb_arraySetND( pItem, 4, te.height    );
      hb_arraySetND( pItem, 5, te.x_advance );
      hb_arraySetND( pItem, 6, te.y_advance );
   }
}
