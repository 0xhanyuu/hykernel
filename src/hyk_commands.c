#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hyk_enums.h"

extern char hykernel_directory[128];

void run_command(e_command current_command)
{
	switch(current_command)
	{
		case nop:
		{
		}
		break;

		case list:
		{
		}
		break;

		case sanity_check:
		{
			printf("%s\n", "symlink should output the following: ");
			printf("%s\n", "kernel -> /usr/src/linux");
		}
		break;

		case set:
		{
		}
		break;

		case show:
		{
		}
		break;

		case version:
		{
		}
		break;

		case help:
		{
		}
		break;
	}
}


// rework

e_command get_command(int argc, char **argv)
{
    char command[16];
    strcpy(command, argv[0]);

	switch(command[0]) // look at first character
	{
		case 'n':
        if ( strcmp(command, "") == 0 )
		    return nop;
		break;

		case 'l':
        if ( strcmp(command, "list") == 0 )
		    return list;
		break;

		case 's':
            switch(command[1]) // look at second character
            {
                case 'a':
                if ( strcmp(command, "sanity_check") == 0 )
                    return sanity_check;
                break;

                case 'e':
                if ( strcmp(command, "set") == 0 )
                    return set;
                break;

                case 'h':

                if ( strcmp(command, "show") == 0 )
                    return show;
                break;
            }
		break;

		case 'v':
        if ( strcmp(command, "version") == 0 )
		    return version;
		break;

		case 'h':
        if ( strcmp(command, "help") == 0 )
		    return help;
		break;

        default:
        fprintf(stderr, "%s\n", "Command not found!");
        return 1;
        break;
	}
}
