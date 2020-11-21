
#include <stdio.h>

#include "hbcairo.h"

int main( void )
{
   cairo_surface_t *surface = cairo_svg_surface_create( "svg-01.svg", 350.0, 100.0 );
   cairo_t *cr = cairo_create( surface );

   cairo_set_source_rgb( cr, 0, 0, 0 );
   cairo_select_font_face( cr, "Courier New", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL );
   cairo_set_font_size( cr, 30 );

   cairo_move_to( cr, 10, 50 );
   cairo_show_text( cr, "Learning Harbour..." );

   cairo_surface_destroy( surface );
   cairo_destroy( cr );
}
