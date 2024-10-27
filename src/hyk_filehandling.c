#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_hykernel() { printf("\e[1m[hykernel]:\e[0m "); }

int file_error()
{
    print_hykernel();
	fprintf(stderr, "Usage: hykernel <command>\n");
	print_hykernel();
    fprintf(stderr, "'hykernel help' for detailed usage information.");

	return EXIT_FAILURE;
}

int file_handling(int argc, char **argv)
{
	// if no additional argument
	if ( argc != 2 )
	{
		return file_error(argv[0]);
	}
    return EXIT_SUCCESS;
}
