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

    lib_table = realloc( lib_table, sizeof( Library ) * lib_table_size+1 );
    lib_table[lib_table_size] = lib;

    return lib_table_size++;

}

extern int init_liblib() {

#ifdef DEBUG_LIBLIB
    printf("Loading liblib\n");
#endif

      /* (re)initialize the library table */
    lib_table = realloc( lib_table, sizeof( Library ) * 1 );
    lib_table[0].lang = LANG_No_Language;

}

extern int call_lib_function( int library_index, const char *function, int arg ) {

    if (library_index < 0) {
        liblib_error("library index %i less than zero", library_index);
        return -1;
    } else if (library_index >= lib_table_size) {
        liblib_error("library index %i greater than max, %i", library_index, lib_table_size);
        return -1;
    }

    /*
    va_list argp;
    va_start( argp, argc );
    */

#ifdef DEBUG_LIBLIB
    printf("Language:           %i\n", lib_table[library_index].lang);
    printf("Function pointer:   %p\n", lib_table[library_index].fp);
    printf("Function pointer(): %p\n", lib_table[library_index].fp( &lib_table[library_index], function ));
    fflush( stdout );
#endif

    return lib_table[library_index].fp( &lib_table[library_index], function )( arg );

}

 // Each langauge has its own C code section
 // You can therefore remove language support trivially
#include "C/all.c"
//#include "Python/all.c"

