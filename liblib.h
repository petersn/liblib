/*
 * Liblibrary header
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#ifdef DEBUG_LIBLIB
#warning Compiling in debug mode!
#endif

typedef enum {

    LANG_No_Language,
    LANG_C,
    LANG_Python,

} Language;

typedef struct _library {

    Language lang;

    /*
     * Just to clarify this ungodly type:
     *   A function pointer that takes a string, and returns the corresponding function.
     *   Functions returned by the lookup function take a void *, and return a void *.
     */
    int (*( (*fp)( struct _library *lib, const char *symbol ) ))(int arg);
    void *data;

} Library;

void liblib_error( const char *format, ... );
int  liblib_register_library( Library lib );

  /* Interface functions */
extern int init_liblib() __attribute__((constructor));
extern int call_lib_function( int library_index, const char *function, int arg );

  /* Global library table */
int lib_table_size;
Library *lib_table;

  // Language specific headers
#include "C/all.h"
//#include "Python/all.h"

