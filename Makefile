
MAJOR_VERSION=1
MINOR_VERSION=0

OPTIONS=
#OPTIONS=-DDEBUG_LIBLIB

LIBRARIES=-ldl

liblib: liblib.c liblib.h Makefile
	gcc -g -fPIC $(OPTIONS) $(LIBRARIES) -c liblib.c
	ld -shared -soname liblib.so.$(MAJOR_VERSION) -o liblib.so.$(MAJOR_VERSION).$(MINOR_VERSION) -lc liblib.o

