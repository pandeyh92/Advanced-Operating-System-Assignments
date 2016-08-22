/* xsh_hello.c - xsh_hello */

#include <xinu.h>
#include <stdio.h>
#include <string.h>

shellcmd xsh_hello(int nargs, char *args[])
{
/* Output info for '--help' argument */

	if (nargs == 2 && strncmp(args[1], "--help", 7) == 0) {
		printf("Usage: %s\n\n", args[0]);
		printf("Description:\n");
		printf("\tDisplays hello\n");
		return 0;
	}
	/* Check for valid number of arguments */

	if (nargs > 2) {
		fprintf(stderr, "%s: too many arguments\n", args[0]);
                fprintf(stderr, "Try '%s --help' for more information\n",args[0]);
	return 1;
	}
	else if (nargs < 2) {
		fprintf(stderr, "%s: too few arguments\n", args[0]);
                fprintf(stderr, "Try '%s --help' for more information\n",args[0]);
		return 1;
	}
	else if (nargs == 2) {
		printf("Hello %s, Welcome to the world of Xinu!!\n", args[1]);
		return 0;
	}

	
}
