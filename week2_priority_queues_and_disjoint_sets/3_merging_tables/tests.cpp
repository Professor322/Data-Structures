//
// Created by professor on 7/21/20.
//

#include <stdlib.h>

int foo(int x, int y) {
	return 2 * x + y;
}

int 	main(int argc, char** argv) {
	int a;
	a = atoi(argv[1]);
	return foo(argc, a);
}
