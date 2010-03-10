/*
 * Liblibrary
 */

#include "liblib.h"

int lib_table_size = 1;
Library *lib_table = NULL;

void liblib_error( const char *format, ... ) {

    va_list argp;
    va_start( argp, format );

    fprintf( stderr, "Error in liblib.so: " );
    vfprintf( stderr, format, argp );
    fprintf( stderr, "\n" );
    fflush( stderr );

    va_end( argp );

}

int liblib_register_library( Library lib ) {
}

extern int init_liblib() {

#ifdef DEBUG_LIBLIB
    printf("Loading liblib\n");
#endif

      /* (re)initialize the library table */
    lib_table = realloc( lib_table, sizeof( Library ) * 1 );
    lib_table[0].lang = LANG_No_Language;

}

/*
extern int call_liblib_loader( Library (*loader)( char *resource ), char *resource ) {
    Library lib;
}
*/

 // Each langauge has its own C code section
 // You can therefore remove language support trivially
#include "C/all.c"
//#include "Python/all.c"

