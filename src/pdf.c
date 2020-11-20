/*
 * Cairo library: pdf
 *
 * Copyright 2020 Rafał Jopek ( rafaljopek at hotmail com )
 *
 * Copyright 2009 Mindaugas Kavaliauskas <dbtopas at dbtopas.lt>
 *
 * PDF Surfaces — Rendering PDF documents
 *
 * Types and Values
 *
 * #define	CAIRO_HAS_PDF_SURFACE
 * #define	CAIRO_PDF_OUTLINE_ROOT
 * enum	   cairo_pdf_outline_flags_t
 * enum	   cairo_pdf_metadata_t
 * enum	   cairo_pdf_version_t
 *
 */

#include "hbcairo.h"

// cairo_surface_t *cairo_pdf_surface_create( const char *filename, double width_in_points, double height_in_points );
HB_FUNC( CAIRO_PDF_SURFACE_CREATE )
{
#ifdef CAIRO_HAS_PDF_SURFACE

   if( hb_param( 1, HB_IT_STRING ) != NULL && hb_param( 2, HB_IT_DOUBLE ) != NULL && hb_param( 3, HB_IT_DOUBLE ) != NULL  )
   {
      hb_cairo_surface_ret( cairo_pdf_surface_create( hb_parc( 1 ), hb_parnd( 2 ), hb_parnd( 3 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }

#else
   hb_retptr( NULL );
#endif
}

// cairo_surface_t *cairo_pdf_surface_create_for_stream( cairo_write_func_t write_func, void *closure, double width_in_points, double height_in_points );
HB_FUNC( CAIRO_PDF_SURFACE_CREATE_FOR_STREAM )
{
}

// void cairo_pdf_surface_restrict_to_version( cairo_surface_t *surface, cairo_pdf_version_t version );
HB_FUNC( CAIRO_PDF_SURFACE_RESTRICT_TO_VERSION )
{
#ifdef CAIRO_HAS_PDF_SURFACE

   cairo_surface_t * pSurface = hb_cairo_surface_param( 1 );

   if( pSurface && hb_param( 2, HB_IT_INTEGER ) != NULL  )
   {
      cairo_pdf_surface_restrict_to_version( pSurface, ( cairo_pdf_version_t ) hb_parni( 2 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }

#else
   /* Just paramter validation */
   hb_cairo_surface_param( 1 );
#endif
}

// void cairo_pdf_get_versions( cairo_pdf_version_t const **versions, int *num_versions );
HB_FUNC( CAIRO_PDF_GET_VERSIONS )
{
}

// const char *cairo_pdf_version_to_string( cairo_pdf_version_t version );
HB_FUNC( CAIRO_PDF_VERSION_TO_STRING )
{
#ifdef CAIRO_HAS_PDF_SURFACE

   if( hb_param( 1, HB_IT_INTEGER ) != NULL )
   {
      hb_retc( cairo_pdf_version_to_string( ( cairo_pdf_version_t ) hb_parni( 1 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }

#else
   hb_ret( NULL )
#endif
}

// void cairo_pdf_surface_set_size( cairo_surface_t *surface, double width_in_points, double height_in_points );
HB_FUNC( CAIRO_PDF_SURFACE_SET_SIZE )
{
#ifdef CAIRO_HAS_PDF_SURFACE

   cairo_surface_t * pSurface = hb_cairo_surface_param( 1 );

   if( pSurface && hb_param( 2, HB_IT_DOUBLE ) != NULL && hb_param( 3, HB_IT_DOUBLE ) != NULL )
   {
      cairo_pdf_surface_set_size( pSurface, hb_parnd( 2 ), hb_parnd( 3 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }

#else
   /* Just paramter validation */
   hb_cairo_surface_param( 1 );
#endif
}

// int cairo_pdf_surface_add_outline( cairo_surface_t *surface, int parent_id, const char *utf8, const char *link_attribs, cairo_pdf_outline_flags_t flags );
HB_FUNC( CAIRO_PDF_SURFACE_ADD_OUTLINE )
{
#ifdef CAIRO_HAS_PDF_SURFACE

   cairo_surface_t * pSurface = hb_cairo_surface_param( 1 );

   if( pSurface && hb_param( 2, HB_IT_INTEGER ) != NULL && hb_param( 3, HB_IT_STRING ) != NULL && hb_param( 4, HB_IT_STRING ) != NULL && hb_param( 5, HB_IT_INTEGER ) != NULL )
   {
      void * hUtf8;
      hb_retni( cairo_pdf_surface_add_outline( pSurface, hb_parni( 2 ), hb_parstr_utf8( 3, &hUtf8, NULL ), hb_parc( 4 ), ( cairo_pdf_outline_flags_t ) hb_parni( 5 ) ) );
      hb_strfree( hUtf8 );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }

#else
   /* Just paramter validation */
   hb_cairo_surface_param( 1 );
#endif
}

// void cairo_pdf_surface_set_metadata( cairo_surface_t *surface, cairo_pdf_metadata_t metadata, const char *utf8 );

// void cairo_pdf_surface_set_page_label( cairo_surface_t *surface, const char *utf8 );

// void cairo_pdf_surface_set_thumbnail_size( cairo_surface_t *surface, int width, int height );
{
HB_FUNC( CAIRO_PDF_SURFACE_SET_THUMBNAIL_SIZE )
#ifdef CAIRO_HAS_PDF_SURFACE

   cairo_surface_t * pSurface = hb_cairo_surface_param( 1 );

   if( pSurface && hb_param( 2, HB_IT_INTEGER ) != NULL && hb_param( 3, HB_IT_INTEGER ) != NULL )
   {
      cairo_pdf_surface_set_thumbnail_size( pSurface, hb_parni( 2 ), hb_parni( 3 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }

#else
   /* Just paramter validation */
   hb_cairo_surface_param( 1 );
#endif
}
