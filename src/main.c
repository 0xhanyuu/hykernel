#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

#include "hyk_commands.h"
#include "hyk_filehandling.h"
#include "hyk_enums.h"

char * command_list[6] =
{
	"list", "set",
	"show", "sanity_check",
	"version", "help"
};

char hykernel_directory[128];
char kernel_list_directory[128];

int main(int argc, char **argv)
{
	e_command current_command;

    /*
	char * hykd_buffer = (char *)malloc(128 * sizeof(char));

	ssize_t executable_len = readlink(
		"/proc/self/exe",
		hykd_buffer,
		sizeof(hykernel_directory) - 1
	);
	
	char * lso_ptr = strrchr(hykd_buffer, '/');
	*(lso_ptr + 1) = '\x00';
	strcpy(hykernel_directory, hykd_buffer);

	free(hykd_buffer);

	if ( executable_len != -1 )
	{
		hykernel_directory[executable_len] = '\x00';	
		printf("exec path: %s\n", hykernel_directory);
	}
	else
	{
		perror("readlink");
		return EXIT_FAILURE;
	}
    */

    

	if ( file_handling(argc, argv) == EXIT_FAILURE )
    {
        return EXIT_FAILURE;
    }

	current_command = get_command(argc, argv);
	run_command(current_command);

	return 0;
}
