#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int file_error()
{
	fprintf(stderr, "usage: hykernel <command>\n");
	fprintf(stderr, "'hykernel help' for detailed usage information\n\n");

	return EXIT_FAILURE;
}

void print_hykernel() { printf("\e[1m[hykernel]:\e[0m "); }

int check_validity(char * input_string) { return 0; }

int file_handling(int argc, char **argv)
{
	// if no additional argument
	if ( argc != 2 )
	{
		return file_error(argv[0]);
		file_error();
	}

	// if filename, check validity
	int return_code = check_validity(argv[1]);
}
