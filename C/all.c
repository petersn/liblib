 /* Code for C support */

  /* Please forgive me for this next line... */
void *(*( (_C_lookup_symbol)( const char *symbol ) ))(void *) {

    char *error;

    if ((error = dlerror()) != NULL) {
        liblib_error( "%s", error );
    }

}

Library load_library_C( char *path ) {

    void *handle;
    Library result;

    printf("Loading library: %s\n", path);

    handle = dlopen( path, RTLD_LAZY );
    if (!handle) {
        liblib_error("couldn't load C library: %s", path);
    }

      /* Begin packing our result library struct */
    result.lang = LANG_C;
    result.data = handle;
    result.fp   = _C_lookup_symbol;

}

