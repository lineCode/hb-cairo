
#include "hbcairo.ch"

PROCEDURE Main()

   LOCAL pSurface
   LOCAL pCairo

   pSurface := cairo_svg_Surface_create( "svg_01.svg", 350.0, 100.0 )
   pCairo   := cairo_create( pSurface )

   cairo_set_source_rgb( pCairo, 0, 0, 0 )
   cairo_select_font_face( pCairo, "Courier New", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL )
   cairo_set_font_size( pCairo, 30 )

   cairo_move_to( pCairo, 10, 50 )
   cairo_show_text( pCairo, "Learning Harbour..." )

   cairo_Surface_destroy( pSurface )
   cairo_destroy( pCairo )

   RETURN
