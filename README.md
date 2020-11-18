# ![svg](docs/assets/img/harbour_cairo.svg) hb-cairo

hb-cairo is a **Harbour** module providing bindings for the [Cairo](https://www.cairographics.org/) graphics library. It is a continuation of an old project from 2009 by the author of *Mindaugas Kavaliauskas*. The project has an educational nature - the main goal is to expand knowledge in the field of creating the aplications with the usege of Harbour programing language.

### Getting Started

Installing hb-cairo requires cairo including its headers. For more info see [getting started](docs/tutorial/README.md).

### Example code

``` harbour

#include "hbcairo.ch"

PROCEDURE Main()

   LOCAL pSurface
   LOCAL pCr
   LOCAL x, y
   LOCAL pPattern

   pSurface := cairo_svg_surface_create( "svg-00.svg", 500.0, 500.0 )
   pCr := cairo_create( pSurface )

   FOR x = 0 TO 10
      FOR y = 0 TO 10
         cairo_rectangle( pCr, x * 10.0, y * 10.0, 5, 5 )
      NEXT
   NEXT

   pPattern := cairo_pattern_create_radial( 50, 50, 5, 50, 50, 50 )
   cairo_pattern_add_color_stop_rgb( pPattern, 0, 0.75, 0.15, 0.99 )
   cairo_pattern_add_color_stop_rgb( pPattern, 0.9, 1, 1, 1 )

   cairo_set_source( pCr, pPattern )
   cairo_fill( pCr )

   cairo_set_font_size( pCr, 15 )
   cairo_select_font_face( pCr, "Georgia", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD )
   cairo_set_source_rgb( pCr, 0, 0, 0 )

   cairo_move_to( pCr, 10, 25 )
   cairo_show_text( pCr, "Hallo" )

   cairo_move_to( pCr, 10, 75 )
   cairo_show_text( pCr, "Harbour" )

   cairo_destroy( pCr )
   cairo_surface_destroy( pSurface )

   RETURN

```

## The result

![svg](docs/assets/img/svg.svg)
