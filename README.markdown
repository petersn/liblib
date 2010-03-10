liblibrary
==========

**liblibrary** is a library for interfacing various libraries regardless of language.

The primary functions:

* To allow arbitrary functions to call each other between languages.
* To define abstract data types that are common to many languages.

### Terminology

An **interface** to liblib from language X is code to import/include/link liblib from within X.

An **outerface** to language X from liblib is support in liblib to call functions in X.

A language is fully supported when it has an interface and an outerface.

----------------

Languages with liblib interfaces:

* C
* Python

Languages with liblib outerfaces:

* C

Note that currently this just makes for a rather pointless interface to use
a C library to call C from Python. Or worse, call C using a C library from C.
Just you wait, it'll get awesome.

Languages on the support wishlist:

* C
* Python
* Mathematica

