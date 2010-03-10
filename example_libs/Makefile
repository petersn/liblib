
c: C.c Makefile
	gcc -g -fPIC -c C.c -o example_c.o
	ld -shared -soname example_c.so.1 -o example_c.so.1.0 -lc example_c.o

