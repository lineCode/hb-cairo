
#include "hbcairo.ch"

PROCEDURE Main()

   LOCAL pSurface
   LOCAL pCr

   pSurface := cairo_svg_surface_create( "svg_01.svg", 350.0, 100.0 )
   pCr := cairo_create( pSurface )

   cairo_set_source_rgb( pCr, 0, 0, 0 )
   cairo_select_font_face( pCr, "Courier New", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL )
   cairo_set_font_size( pCr, 30 )

   cairo_move_to( pCr, 10, 50 )
   cairo_show_text( pCr, "Learning Harbour..." )

   cairo_surface_destroy( pSurface )
   cairo_destroy( pCr )

   RETURN
