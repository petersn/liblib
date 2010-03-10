#include <stdio.h>

extern int print_int( int arg ) {

	printf("Integer argument passed: %i\n", arg);

	return arg*2;

}

