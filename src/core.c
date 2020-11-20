/*
 * Cairo library: core
 *
 * Copyright 2020 Rafał Jopek ( rafaljopek at hotmail com )
 *
 * Copyright 2009 Mindaugas Kavaliauskas <dbtopas at dbtopas.lt>
 *
 */

#include "hbcairo.h"

/* --- cairo_t * support --- */
static HB_GARBAGE_FUNC( hb_cairo_destructor )
{
   cairo_t ** ppCairo = ( cairo_t ** ) Cargo;

   if( *ppCairo )
   {
      cairo_destroy( *ppCairo );
      *ppCairo = NULL;
   }
}

static const HB_GC_FUNCS s_gcCairoFuncs =
{
   hb_cairo_destructor,
   hb_gcDummyMark
};

cairo_t * hb_cairoItemGet( PHB_ITEM pItem )
{
   cairo_t ** ppCairo = ( cairo_t ** ) hb_itemGetPtrGC( pItem, &s_gcCairoFuncs );

   return ppCairo ? *ppCairo : NULL;
}

PHB_ITEM hb_cairoItemPut( PHB_ITEM pItem, cairo_t * pCairo )
{
   cairo_t ** ppCairo = ( cairo_t ** ) hb_gcAllocate( sizeof( cairo_t * ), &s_gcCairoFuncs );

   *ppCairo = pCairo;
   return hb_itemPutPtrGC( pItem, ppCairo );
}

cairo_t * hb_cairo_param( int iParam )
{
   cairo_t ** ppCairo = ( cairo_t ** ) hb_parptrGC( &s_gcCairoFuncs, iParam );

   if( ppCairo && *ppCairo )
   {
      return *ppCairo;
   }

   hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   return NULL;
}

void hb_cairo_ret( cairo_t * pCairo )
{
   hb_cairoItemPut( hb_stackReturnItem(), pCairo );
}

HB_FUNC( CAIRO_DESTROY )
{
   cairo_t ** ppCairo = ( cairo_t ** ) hb_parptrGC( &s_gcCairoFuncs, 1 );

   if( ppCairo && *ppCairo )
   {
      cairo_destroy( *ppCairo );
      *ppCairo = NULL;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

/* --- cairo_path_t * support --- */
static HB_GARBAGE_FUNC( hb_cairo_path_destructor )
{
   cairo_path_t ** ppPath = ( cairo_path_t ** ) Cargo;

   if( *ppPath )
   {
      cairo_path_destroy( *ppPath );
      *ppPath = NULL;
   }
}

static const HB_GC_FUNCS s_gcPathFuncs =
{
   hb_cairo_path_destructor,
   hb_gcDummyMark
};

cairo_path_t * hb_cairoPathItemGet( PHB_ITEM pItem )
{
   cairo_path_t ** ppPath = ( cairo_path_t ** ) hb_itemGetPtrGC( pItem, &s_gcPathFuncs );

   return ppPath ? *ppPath : NULL;
}

PHB_ITEM hb_cairoPathItemPut( PHB_ITEM pItem, cairo_path_t * pPath )
{
   cairo_path_t ** ppPath = ( cairo_path_t ** ) hb_gcAllocate( sizeof( cairo_path_t * ), &s_gcPathFuncs );

   *ppPath = pPath;
   return hb_itemPutPtrGC( pItem, ppPath );
}

cairo_path_t * hb_cairo_path_param( int iParam )
{
   cairo_path_t ** ppPath = ( cairo_path_t ** ) hb_parptrGC( &s_gcPathFuncs, iParam );

   if( ppPath && *ppPath )
   {
      return *ppPath;
   }

   hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   return NULL;
}

void hb_cairo_path_ret( cairo_path_t * pPath )
{
   hb_cairoPathItemPut( hb_stackReturnItem(), pPath );
}

HB_FUNC( CAIRO_PATH_DESTROY )
{
   cairo_path_t ** ppPath = ( cairo_path_t ** ) hb_parptrGC( &s_gcPathFuncs, 1 );

   if( ppPath && *ppPath )
   {
      cairo_path_destroy( *ppPath );
      *ppPath = NULL;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

/* --- cairo_pattern_t * support --- */
static HB_GARBAGE_FUNC( hb_cairo_pattern_destructor )
{
   cairo_pattern_t ** ppPattern = ( cairo_pattern_t ** ) Cargo;

   if( *ppPattern )
   {
      cairo_pattern_destroy( *ppPattern );
      *ppPattern = NULL;
   }
}

static const HB_GC_FUNCS s_gcPatternFuncs =
{
   hb_cairo_pattern_destructor,
   hb_gcDummyMark
};

cairo_pattern_t * hb_cairoPatternItemGet( PHB_ITEM pItem )
{
   cairo_pattern_t ** ppPattern = ( cairo_pattern_t ** ) hb_itemGetPtrGC( pItem, &s_gcPatternFuncs );

   return ppPattern ? *ppPattern : NULL;
}

PHB_ITEM hb_cairoPatternItemPut( PHB_ITEM pItem, cairo_pattern_t * pPattern )
{
   cairo_pattern_t ** ppPattern = ( cairo_pattern_t ** ) hb_gcAllocate( sizeof( cairo_pattern_t * ), &s_gcPatternFuncs );

   *ppPattern = pPattern;
   return hb_itemPutPtrGC( pItem, ppPattern );
}

cairo_pattern_t * hb_cairo_pattern_param( int iParam )
{
   cairo_pattern_t ** ppPattern = ( cairo_pattern_t ** ) hb_parptrGC( &s_gcPatternFuncs, iParam );

   if( ppPattern && *ppPattern )
   {
      return *ppPattern;
   }

   hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   return NULL;
}

void hb_cairo_pattern_ret( cairo_pattern_t * pPattern )
{
   hb_cairoPatternItemPut( hb_stackReturnItem(), pPattern );
}

HB_FUNC( CAIRO_PATTERN_DESTROY )
{
   cairo_pattern_t ** ppPattern = ( cairo_pattern_t ** ) hb_parptrGC( &s_gcPatternFuncs, 1 );

   if( ppPattern && *ppPattern )
   {
      cairo_pattern_destroy( *ppPattern );
      *ppPattern = NULL;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

/* --- cairo_surface_t * support --- */
static HB_GARBAGE_FUNC( hb_cairo_surface_destructor )
{
   cairo_surface_t ** ppSurface = ( cairo_surface_t ** ) Cargo;

   if( *ppSurface )
   {
      cairo_surface_destroy( *ppSurface );
      *ppSurface = NULL;
   }
}

static const HB_GC_FUNCS s_gcSurfaceFuncs =
{
   hb_cairo_surface_destructor,
   hb_gcDummyMark
};

cairo_surface_t * hb_cairoSurfaceItemGet( PHB_ITEM pItem )
{
   cairo_surface_t ** ppSurface = ( cairo_surface_t ** ) hb_itemGetPtrGC( pItem, &s_gcSurfaceFuncs );

   return ppSurface ? *ppSurface : NULL;
}

PHB_ITEM hb_cairoSurfaceItemPut( PHB_ITEM pItem, cairo_surface_t * pSurface )
{
   cairo_surface_t ** ppSurface = ( cairo_surface_t ** ) hb_gcAllocate( sizeof( cairo_surface_t * ), &s_gcSurfaceFuncs );

   *ppSurface = pSurface;
   return hb_itemPutPtrGC( pItem, ppSurface );
}

void hb_cairoSurfaceStor( cairo_surface_t * pSurface, int iParam )
{
   cairo_surface_t ** ppSurface = ( cairo_surface_t ** ) hb_gcAllocate( sizeof( cairo_surface_t * ), &s_gcSurfaceFuncs );

   *ppSurface = pSurface;
   hb_storptrGC( ppSurface, iParam );
}

cairo_surface_t * hb_cairo_surface_param( int iParam )
{
   cairo_surface_t ** ppSurface = ( cairo_surface_t ** ) hb_parptrGC( &s_gcSurfaceFuncs, iParam );

   if( ppSurface && *ppSurface )
   {
      return *ppSurface;
   }

   hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   return NULL;
}

void hb_cairo_surface_ret( cairo_surface_t * pSurface )
{
   hb_cairoSurfaceItemPut( hb_stackReturnItem(), pSurface );
}

HB_FUNC( CAIRO_SURFACE_DESTROY )
{
   cairo_surface_t ** ppSurface = ( cairo_surface_t ** ) hb_parptrGC( &s_gcSurfaceFuncs, 1 );

   if( ppSurface && *ppSurface )
   {
      cairo_surface_destroy( *ppSurface );
      *ppSurface = NULL;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

/* --- cairo_path_t * iterator support --- */

/* NOTE: Path iterator functions are is not cairo functions.
         This is only a way to pass path data to .prg level */

typedef struct
{
   cairo_path_t ** ppPath;
   int iPos;
} HB_CAIRO_PATH_ITERATOR, * PHB_CAIRO_PATH_ITERATOR;

static HB_GARBAGE_FUNC( hb_cairo_path_iterator_destructor )
{
   PHB_CAIRO_PATH_ITERATOR pIterator = ( PHB_CAIRO_PATH_ITERATOR ) Cargo;

   if( pIterator->ppPath )
   {
      hb_gcRefFree( pIterator->ppPath );
      pIterator->ppPath = NULL;
   }
}

static HB_GARBAGE_FUNC( hb_cairo_path_iterator_mark )
{
   PHB_CAIRO_PATH_ITERATOR pIterator = ( PHB_CAIRO_PATH_ITERATOR ) Cargo;

   if( pIterator->ppPath )
   {
      hb_gcMark( pIterator->ppPath );
   }
}

static const HB_GC_FUNCS s_gcIteratorFuncs =
{
   hb_cairo_path_iterator_destructor,
   hb_cairo_path_iterator_mark
};

HB_FUNC( CAIRO_PATH_ITERATOR_CREATE )
{
   cairo_path_t ** ppPath = ( cairo_path_t ** ) hb_parptrGC( &s_gcPathFuncs, 1 );

   if( ppPath && *ppPath )
   {
      PHB_CAIRO_PATH_ITERATOR pIterator = ( PHB_CAIRO_PATH_ITERATOR ) hb_gcAllocate( sizeof( HB_CAIRO_PATH_ITERATOR ), &s_gcIteratorFuncs );
      pIterator->ppPath = ppPath;
      hb_gcRefInc( ppPath );
      pIterator->iPos = -1;
      hb_itemPutPtrGC( hb_stackReturnItem(), pIterator );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

HB_FUNC( CAIRO_PATH_ITERATOR_DESTROY )
{
   PHB_CAIRO_PATH_ITERATOR pIterator = ( PHB_CAIRO_PATH_ITERATOR ) hb_parptrGC( &s_gcIteratorFuncs, 1 );

   if( pIterator && pIterator->ppPath )
   {
      hb_gcRefFree( pIterator->ppPath );
      pIterator->ppPath = NULL;
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

HB_FUNC( CAIRO_PATH_ITERATOR_NEXT )
{
   PHB_CAIRO_PATH_ITERATOR pIterator = ( PHB_CAIRO_PATH_ITERATOR ) hb_parptrGC( &s_gcIteratorFuncs, 1 );
   cairo_path_t *          pPath;

   if( pIterator && pIterator->ppPath && ( pPath = *( pIterator->ppPath ) ) != NULL )
   {
      /* Skip */
      if( pIterator->iPos == -1 )
      {
         pIterator->iPos = 0;
      }
      else if( pIterator->iPos < pPath->num_data )
      {
         pIterator->iPos += pPath->data[ pIterator->iPos ].header.length;
      }

      /* return type */
      if( pIterator->iPos < pPath->num_data )
      {
         hb_retni( pPath->data[ pIterator->iPos ].header.type );
      }
      else
      {
         hb_ret();
      }
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

HB_FUNC( CAIRO_PATH_ITERATOR_GET_POINTS )
{
   PHB_CAIRO_PATH_ITERATOR pIterator = ( PHB_CAIRO_PATH_ITERATOR ) hb_parptrGC( &s_gcIteratorFuncs, 1 );
   cairo_path_t *          pPath;

   if( pIterator && pIterator->ppPath && ( pPath = *( pIterator->ppPath ) ) != NULL )
   {
      if( pIterator->iPos < pPath->num_data && pIterator->iPos != -1 )
      {
         cairo_path_data_t * pData;
         PHB_ITEM pArray;
         int      i;

         pData  = pPath->data + pIterator->iPos;
         pArray = hb_itemArrayNew( pData->header.length - 1 );
         for( i = 1; i < pData->header.length; i++ )
         {
            PHB_ITEM pItem = hb_arrayGetItemPtr( pArray, i );
            hb_arrayNew( pItem, 2 );
            hb_arraySetND( pItem, 1, pData[ i ].point.x );
            hb_arraySetND( pItem, 2, pData[ i ].point.y );
         }
         hb_itemReturnRelease( pArray );
      }
      else
      {
         hb_ret();
      }
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

HB_FUNC( CAIRO_PATH_ITERATOR_SET_POINTS )
{
   PHB_CAIRO_PATH_ITERATOR pIterator = ( PHB_CAIRO_PATH_ITERATOR ) hb_parptrGC( &s_gcIteratorFuncs, 1 );
   PHB_ITEM       pArray = hb_param( 2, HB_IT_ARRAY );
   cairo_path_t * pPath;

   if( pIterator && pIterator->ppPath && ( pPath = *( pIterator->ppPath ) ) != NULL && pArray )
   {
      HB_SIZE nLen;

      nLen = hb_arrayLen( pArray );
      if( pIterator->iPos < pPath->num_data && pIterator->iPos != -1 &&
          ( HB_SIZE ) pPath->data[ pIterator->iPos ].header.length == nLen + 1 )
      {
         cairo_path_data_t * pData;
         int i;

         pData = pPath->data + pIterator->iPos;
         for( i = 1; i < pData->header.length; i++ )
         {
            PHB_ITEM pItem = hb_arrayGetItemPtr( pArray, i );
            if( hb_arrayLen( pItem ) == 2 )
            {
               pData[ i ].point.x = hb_arrayGetND( pItem, 1 );
               pData[ i ].point.y = hb_arrayGetND( pItem, 2 );
            }
            else
            {
               hb_retl( HB_FALSE );
               return;
            }
         }
         hb_retl( HB_TRUE );
      }
      else
      {
         hb_retl( HB_FALSE );
      }
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}
