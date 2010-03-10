C-liblib interface
==================

## To use other languages from C:
Include liblib.h, and compile against liblib.c in order to access liblib functionality.

## To use C from other languages:
Use your local liblib import/include/link step, then run: (translated into your local language)

	`library = liblib.load_lib_C( string path )`

Next you can run C functions with:

	`liblib.call_C( library, "function", arguments ... )`

