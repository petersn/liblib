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

typedef struct {

    Language lang;

    /*
     * Just to clarify this ungodly type:
     *   A function pointer that takes a string, and returns the corresponding function.
     *   Functions returned by the lookup function take a void *, and return a void *.
     */
    void *(*( (*fp)( const char *symbol ) ))(void *);
    void *data;

} Library;

void liblib_error( const char *format, ... );
int  liblib_register_library( Library lib );

extern int init_liblib() __attribute__((constructor));

  /* Global library table */
int lib_table_size;
Library *lib_table;

  /*
   * Main interface function -- call this on a loader to load a library
   *   Return value will be an index into the library table
   */
//extern int call_liblib_loader( Library (*loader)( char *resource ), char *resource );

  // Language specific headers
#include "C/all.h"
//#include "Python/all.h"

