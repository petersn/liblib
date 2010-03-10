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
* Mathematica

Languages with liblib outerfaces:

* C (extremely primitive, only int (*)(int) functions handled properly)

Languages on the support wishlist:

* C
* Python
* Mathematica

