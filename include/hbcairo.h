
#ifndef HB_CAIRO_H_
#define HB_CAIRO_H_

#include "hbapi.h"
#include "hbapierr.h"
#include "hbapiitm.h"
#include "hbapistr.h"
#include "hbstack.h"

#include <cairo/cairo.h>
#include <cairo/cairo-pdf.h>
#include <cairo/cairo-ps.h>
#include <cairo/cairo-svg.h>

HB_EXTERN_BEGIN

/* --- Drawing --- */

extern HB_EXPORT cairo_t *          hb_cairoItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM           hb_cairoItemPut( PHB_ITEM pItem, cairo_t * pCairo );
extern HB_EXPORT cairo_t *          hb_cairo_param( int iParam );
extern HB_EXPORT void               hb_cairo_ret( cairo_t * );

extern HB_EXPORT cairo_path_t *     hb_cairoPathItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM           hb_cairoPathItemPut( PHB_ITEM pItem, cairo_path_t * pPath );
extern HB_EXPORT cairo_path_t *     hb_cairo_path_param( int iParam );
extern HB_EXPORT void               hb_cairo_path_ret( cairo_path_t * pPath );

extern HB_EXPORT cairo_pattern_t *  hb_cairoPatternItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM           hb_cairoPatternItemPut( PHB_ITEM pItem, cairo_pattern_t * pPattern );
extern HB_EXPORT cairo_pattern_t *  hb_cairo_pattern_param( int iParam );
extern HB_EXPORT void               hb_cairo_pattern_ret( cairo_pattern_t * pPattern );

/* --- Surfaces --- */

extern HB_EXPORT cairo_surface_t *  hb_cairoSurfaceItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM           hb_cairoSurfaceItemPut( PHB_ITEM pItem, cairo_surface_t * pSurface );
extern HB_EXPORT void               hb_cairoSurfaceStor( cairo_surface_t * pSurface, int iParam );
extern HB_EXPORT cairo_surface_t *  hb_cairo_surface_param( int iParam );
extern HB_EXPORT void               hb_cairo_surface_ret( cairo_surface_t * pSurface );

HB_EXTERN_END

#endif /* HB_CAIRO_H_ */
