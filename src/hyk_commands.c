#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hyk_enums.h"
#include "hyk_filehandling.h"

extern char hykernel_directory[128];
extern char kernel_list_directory[128];

void print_hykernel() { printf("\e[1m[hykernel]:\e[0m "); }
void e_print_hykernel() { fprintf(stderr, "\e[1m[hykernel]:\e[0m "); }

void output_help()
{

}

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
            char * tmp_command = (char *)malloc(256 * sizeof(char));
            snprintf(tmp_command, 256,
                "count=0; for kernel in $(ls %s); do "
                "echo \"$((++count)). $kernel\"; "
                "done", kernel_list_directory
            );
            system(tmp_command);
            free(tmp_command);
		}
		break;

		case sanity_check:
		{
            print_hykernel();
			printf("%s\n", "Symlink should output the following: ");
			print_hykernel();
            printf("%s\n", "/usr/src/linux -> <kernel>");
		}
		break;

		case set:
		{
            //// set given number to kernel
		    // append kernel to kernel directory in a buffer,
            // set current kernel to buffer
            // ln -s %s /usr/src/linux
            //       ^ kernel
        }
		break;

		case show:
		{
            // output the directory /usr/src/linux points to
            // i.e. current kernel
            // char * tmp_command = (char *)malloc(256 * sizeof(char));
            // system("ls /usr/src/linux");
		}
		break;

		case version:
		{
            // only relevant for releases
		}
		break;

		case help:
		{
            output_help();
		}
		break;
	}
}


// rework

e_command get_command(char **argv)
{
    char command[16];
    strcpy(command, argv[1]);

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
        e_print_hykernel();
        fprintf(stderr, "%s\n", "Command not found!");
        return 1;
        break;
	}
    return nop;
}
