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
    printf(
    "%s%s%s%s%s%s%s%s%s",
    "hykernel v1.0 \e[1m(pre-release)\e[0m\n",
    "\n",
    "Usage: hykernel <command>\n",
    "   or: hykernel <command> <number>\n",
    "\n",
    "Options:\n"
    "  list\t\tProduces a *numbered* list of all kernel files located\n"
    "  \t\t  in \e[1m/etc/opt/hykernel/kernel_list\e[0m or custom kernel directory\n",
    "  set\t\tSet the \e[1m/usr/src/linux\e[0m symlink to the given kernel through\n"
    "  \t\t  the <number> argument, refer to 'list' to choose correct kernel\n",
    "  show\t\tOutputs the current symlink, given link \e[1m/usr/src/linux\e[0m\n"
    "  \t\t  and chosen kernel being target\n",
    "  help\t\tDisplay this help and exit\n\n"
    );
}

void run_command(e_command current_command, char **argv)
{
	switch(current_command)
	{
		case nop: { } break;

        case add:
        {
            char * add_command = (char *)malloc(512 * sizeof(char));
            char * kernel_to_mv = (char *)malloc(256 * sizeof(char));
            strcpy(kernel_to_mv, argv[2]);

            print_hykernel();
            printf("%s\n", "Appending to /etc/opt/hykernel/tmp ...");

            snprintf(add_command, 512,
                "sudo mv %s /etc/opt/hykernel/kernel_list/ -v" \
                "count=0; for kernel in $(ls %s); do " \
                "echo \"$((++count)). $kernel\"; " \
                "done | sudo tee /etc/opt/hykernel/tmp",
                kernel_to_mv, kernel_list_directory
            );

            free(kernel_to_mv); free(add_command);
        }
        break;

		case list:
		{
            char * list_command = (char *)malloc(512 * sizeof(char));

            snprintf(list_command, 512,
                "count=0; for kernel in $(ls %s); do " \
                "echo \"$((++count)). $kernel\"; " \
                "done", kernel_list_directory
            );

            system(list_command);
            free(list_command);
		}
		break;

		case sanity_check:
		{
            char * sanity_check_command = (char *)malloc(512 * sizeof(char));

            print_hykernel();
			printf("%s\n", "Symlink should output the following: ");
			e_print_hykernel();
            snprintf(
            sanity_check_command, 512,
            "echo \"/usr/src/linux -> %s/<kernel>\"",
            kernel_list_directory
            );

            system(sanity_check_command);

            free(sanity_check_command);
		}
		break;

		case set:
		{
            //// set given number to kernel
		    // append kernel to kernel directory in a buffer,
            // set current kernel to buffer
            // ln -s %s /usr/src/linux
            //       ^ kernel (target)

            char * user_input_str = argv[2]; // user input
            char user_input = user_input_str[0]; // number value from user input
            FILE * tmp_f = fopen("/etc/opt/hykernel/tmp", "r"); // list file
            char * set_command = (char *)malloc(512 * sizeof(char));
            char * chosen_kernel = (char *)malloc(256 * sizeof(char));
            char * f_buffer = (char *)malloc(256 * sizeof(char));
            int current_line = 1;

            // find corresponding number value in list file 
            while ( fgets(f_buffer, sizeof(f_buffer), tmp_f) )
            {
                printf("%s\n", "in while loop !");
                if ( current_line == user_input )
                {
                    printf("%s\n", "found!");
                    
                    strcpy(chosen_kernel, f_buffer);
                    break;
                }
                else
                {
                }
                current_line++;
            }

            snprintf(
            set_command, 512, "sudo ln -s %s/%s /usr/src/linux",
            kernel_list_directory, chosen_kernel);

            printf("set_command:%s\n", set_command);

            // system(set_command);

            free(user_input_str); free(set_command); free(chosen_kernel); free(f_buffer);
        }
		break;

		case show:
		{
            // output the directory /usr/src/linux points to
            // i.e. current kernel
            
            e_print_hykernel();
            system("echo \"/usr/src/$(ls /usr/src -l | grep linux | cut -c42-)\"");
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
