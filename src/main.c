#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

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

	if ( file_handling(argc, argv) == EXIT_FAILURE )
        return EXIT_FAILURE;

    FILE * config_file = fopen("/etc/opt/hykernel/config/config", "r");

    char buffer[64];
    fgets(buffer, sizeof(buffer), config_file); // gets hykernel_directory string
    fgets(buffer, sizeof(buffer), config_file); // gets kernel_directory string

    char current_char = 0;
    int i = 0;

    while ( (current_char = buffer[i]) != '=' )
        i++;

    i++;
    for (int j = 0; j < 128; j++ )
    {
        kernel_list_directory[j] = buffer[i];
        i++;
    }

    fclose(config_file);

    // remove endline character
    kernel_list_directory[strlen(kernel_list_directory) - 1] = '\x00';

	current_command = get_command(argv);
	run_command(current_command, argv);

	return 0;
}
