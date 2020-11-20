/*
 * Cairo library: text
 *
 * Copyright 2020 Rafał Jopek ( rafaljopek at hotmail com )
 *
 * Copyright 2009 Mindaugas Kavaliauskas <dbtopas at dbtopas.lt>
 *
 * text — Rendering text and glyphs
 *
 * Types and Values
 *
 *        cairo_glyph_t
 * enum   cairo_font_slant_t
 * enum   cairo_font_weight_t
 *        cairo_text_cluster_t
 * enum   cairo_text_cluster_flags_t
 *
 */

#include "hbcairo.h"

// void cairo_select_font_face( cairo_t *cr, const char *family, cairo_font_slant_t slant, cairo_font_weight_t weight );
HB_FUNC( CAIRO_SELECT_FONT_FACE )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      void * hFamily;
      cairo_select_font_face( pCairo, hb_parstr_utf8( 2, &hFamily, NULL ), ( cairo_font_slant_t ) hb_parni( 3 ), ( cairo_font_weight_t ) hb_parni( 4 ) );
      hb_strfree( hFamily );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void cairo_set_font_size( cairo_t *cr, double size );
HB_FUNC( CAIRO_SET_FONT_SIZE )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      cairo_set_font_size( pCairo, hb_parnd( 2 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void cairo_set_font_matrix( cairo_t *cr, const cairo_matrix_t *matrix );
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
      {
         hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
      }
   }
}

// void cairo_get_font_matrix( cairo_t *cr, cairo_matrix_t *matrix );
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
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void cairo_set_font_options( cairo_t *cr, const cairo_font_options_t *options );

// void cairo_get_font_options( cairo_t *cr, cairo_font_options_t *options );

// void cairo_set_font_face( cairo_t *cr, cairo_font_face_t *font_face );

// cairo_font_face_t* cairo_get_font_face( cairo_t *cr );

// void cairo_set_scaled_font( cairo_t *cr, const cairo_scaled_font_t *scaled_font );

// cairo_scaled_font_t* cairo_get_scaled_font( cairo_t *cr );

// void cairo_show_text( cairo_t *cr, const char *utf8 );
HB_FUNC( CAIRO_SHOW_TEXT )
{
   cairo_t * pCairo = hb_cairo_param( 1 );

   if( pCairo )
   {
      void * hText;
      cairo_show_text( pCairo, hb_parstr_utf8( 2, &hText, NULL ) );
      hb_strfree( hText );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void cairo_show_glyphs( cairo_t *cr, const cairo_glyph_t *glyphs, int num_glyphs );

// void cairo_show_text_glyphs( cairo_t *cr, const char *utf8, int utf8_len, const cairo_glyph_t *glyphs, int num_glyphs, const cairo_text_cluster_t *clusters, int num_clusters, cairo_text_cluster_flags_t cluster_flags );

// void cairo_font_extents( cairo_t *cr, cairo_font_extents_t *extents );
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
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void cairo_text_extents( cairo_t *cr, const char *utf8, cairo_text_extents_t *extents );
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
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void cairo_glyph_extents( cairo_t *cr, const cairo_glyph_t *glyphs, int num_glyphs, cairo_text_extents_t *extents );

// cairo_font_face_t * cairo_toy_font_face_create( const char *family, cairo_font_slant_t slant, cairo_font_weight_t weight );

// const char * cairo_toy_font_face_get_family( cairo_font_face_t *font_face );

// cairo_font_slant_t cairo_toy_font_face_get_slant( cairo_font_face_t *font_face );

// cairo_font_weight_t cairo_toy_font_face_get_weight( cairo_font_face_t *font_face );

// cairo_glyph_t * cairo_glyph_allocate( int num_glyphs );

// void cairo_glyph_free( cairo_glyph_t *glyphs );

// cairo_text_cluster_t * cairo_text_cluster_allocate( int num_clusters );

// void cairo_text_cluster_free ( cairo_text_cluster_t *clusters );
