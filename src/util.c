/*
 * Cairo library: utility functions
 *
 * Copyright 2020 Rafał Jopek ( rafaljopek at hotmail com )
 *
 * Copyright 2009 Mindaugas Kavaliauskas <dbtopas at dbtopas.lt>
 *
 */

#include "hbcairo.h"

HB_FUNC( CAIRO_STATUS_TO_STRING )
{
   hb_retc( cairo_status_to_string( ( cairo_status_t ) hb_parni( 1 ) ) );
}

HB_FUNC( CAIRO_VERSION )
{
   hb_retni( cairo_version() );
}

HB_FUNC( CAIRO_VERSION_STRING )
{
   hb_retc( cairo_version_string() );
}
