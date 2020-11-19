/*
 * Cairo library: utility functions
 *
 * Copyright 2020 Rafał Jopek ( rafaljopek at hotmail com )
 *
 * Copyright 2009 Mindaugas Kavaliauskas <dbtopas at dbtopas.lt>
 *
 * cairo_matrix_t
 * cairo_matrix_t — Generic matrix operations
 *
 * Types and Values
 *
 *      cairo_matrix_t
 *
 * Error handling
 * Error handling — Decoding cairo's status
 *
 * Types and Values
 *
 * enum cairo_status_t
 *
 * Version Information
 * Version Information — Compile-time and run-time version checks.
 *
 */

#include "hbcairo.h"

/* cairo_matrix_t */

// void cairo_matrix_init( cairo_matrix_t *matrix, double xx, double yx, double xy, double yy, double x0, double y0 );

// void cairo_matrix_init_identity( cairo_matrix_t *matrix );

// void cairo_matrix_init_translate( cairo_matrix_t *matrix, double tx, double ty );

// void cairo_matrix_init_scale( cairo_matrix_t *matrix, double sx, double sy );

// void cairo_matrix_init_rotate( cairo_matrix_t *matrix, double radians);

// void cairo_matrix_translate( cairo_matrix_t *matrix, double tx, double ty );

// void cairo_matrix_scale( cairo_matrix_t *matrix, double sx, double sy );

// void cairo_matrix_rotate( cairo_matrix_t *matrix, double radians);

// cairo_status_t cairo_matrix_invert( cairo_matrix_t *matrix );

// void cairo_matrix_multiply( cairo_matrix_t *result, const cairo_matrix_t *a, const cairo_matrix_t *b );

// void cairo_matrix_transform_distance( const cairo_matrix_t *matrix, double *dx, double *dy );

// void cairo_matrix_transform_point( const cairo_matrix_t *matrix, double *x, double *y );

/* Error handling */

// const char* cairo_status_to_string( cairo_status_t status );
HB_FUNC( CAIRO_STATUS_TO_STRING )
{
   hb_retc( cairo_status_to_string( ( cairo_status_t ) hb_parni( 1 ) ) );
}

// void cairo_debug_reset_static_data( void );

/* Version Information */

// int cairo_version ()
HB_FUNC( CAIRO_VERSION )
{
   hb_retni( cairo_version() );
}

// const char * cairo_version_string ()
HB_FUNC( CAIRO_VERSION_STRING )
{
   hb_retc( cairo_version_string() );
}
