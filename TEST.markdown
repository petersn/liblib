## To test:

Run:

    make
    cd example_libs
    make
    cd ..
    python

Then, from within python:

    from Python import liblib
    lib = liblib.Library("C", "example_libs/example_c.so.1.0")
    lib("print_int", 13)

