#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int file_error()
{
    e_print_hykernel();
	fprintf(stderr, "Usage: hykernel <command>\n");
	e_print_hykernel();
    fprintf(stderr, "'hykernel help' for detailed usage information.\n");

	return EXIT_FAILURE;
}

int file_handling(int argc, char **argv)
{
	// if no additional argument
	if ( argc != 2 )
	{
		return file_error();
	}
    return EXIT_SUCCESS;
}
