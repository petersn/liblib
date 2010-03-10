C-liblib interface
==================

### To use other languages from C:
Include liblib.h, and compile against liblib.c in order to access liblib functionality.

### To use C from other languages:
(Examples in Python. Translate everything into your local language.)

Use your local liblib import/include/link step, then run:

    library = liblib.load_lib_C( "path" )

Next you can run C functions with:

    liblib.call_C( library, "function", arguments ... )

You can also read/write variables of this library with:

    liblib.write_var_C( library, "variable", value )
    x = liblib.read_var_C( library, "variable" )

