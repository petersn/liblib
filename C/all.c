 /* Code for C support */

  /* Please forgive me for this next line... */
int (*( (_C_lookup_symbol)( Library *lib, const char *symbol ) ))(int arg) {

    char *error;
    void *function_pointer;

    function_pointer = dlsym( lib->data, symbol );

    if ((error = dlerror()) != NULL) {
        liblib_error( "%s", error );
    }

    return function_pointer;

}

int load_library_C( char *path ) {

    void *handle;
    Library lib;

    printf("Loading library: %s\n", path);

    handle = dlopen( path, RTLD_LAZY );
    if (!handle) {
        liblib_error("couldn't load C library: %s", path);
    }

      /* Begin packing our result library struct */
    lib.lang = LANG_C;
    lib.data = handle;
    lib.fp   = _C_lookup_symbol;

    return liblib_register_library( lib );

}

