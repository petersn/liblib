
extern int load_library_C P(( const char *path ));

:Begin:
:Function:      load_library_C
:Pattern:       LoadLibraryC[s_String]
:Arguments:     {s}
:ArgumentTypes: {String}
:ReturnType:    Integer
:End:

:Evaluate: LoadLibraryC::usage = "LoadLibraryC[path] loads the shared object at path, or searches for the system SO path"

extern int call_lib_function( int library_index, const char *function, int arg );

:Begin:
:Function:      call_lib_function
:Pattern:       CallLibFunction[index_Integer, function_String, arg_Integer]
:Arguments:     {index, function, arg}
:ArgumentTypes: {Integer, String, Integer}
:ReturnType:    Integer
:End:

:Evaluate: LoadLibraryC::usage = "CallLibFunction[lib, function, arg] calls a function from a loaded library"

