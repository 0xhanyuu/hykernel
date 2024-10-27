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

	if ( file_handling(argc, argv) == EXIT_FAILURE )
    {
        return EXIT_FAILURE;
    }

	current_command = get_command(argc, argv);
	run_command(current_command);

	return 0;
}
