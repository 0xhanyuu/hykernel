#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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

enum command get_command(int argc, char **argv)
{
	char first_character = argv[1][0];
	char second_character = argv[1][1];

	switch(first_character)
	{
		case 'l':
		return list;
		break;

		case 's':
		switch(second_character)
		{
			case 'a':
			return sanity_check;
			break;

			case 'e':
			return set;
			break;

			case 'h':
			return show;
			break;
		}
		break;

		case 'v':
		return version;
		break;

		case 'h':
		return help;
		break;
	}
}

void run_command(enum command current_command)
{
	switch(current_command)
	{
		case list: // done !
		{
			printf("[hykernel]: current kernel list:\n");
			system("ls -AL /usr/lib/modules");
		}
		break;

		case sanity_check: // done ?
		{
			print_hykernel();
			printf("sanity check should output the following:\n");
			print_hykernel();
			printf("/usr/src/linux -> set_kernel_version\n");
			print_hykernel();
			system("ls -l /usr/src | grep linux");
		}
		break;

		case set:
		{
			char * kernel = (char *)malloc(32 * sizeof(char));
			char * command_buffer = (char *)malloc(128 * sizeof(char));

			printf("%s\n", "input kernel name: ");
			scanf("%s", kernel);

			snprintf(command_buffer, 128, "sudo ln -s /usr/src/linux %s", kernel);

			printf("command_buffer: %s\n", command_buffer);
			free(command_buffer); free(kernel);

			//system(command_buffer);
			//printf("set done !");
		}
		break;

		case show:
		{
			system("ls /usr/src/linux");
			//output symlink kernel
		}
		break;

		case version:
		{
			char * version_path = (char *)malloc(bytes_read * sizeof(char));

			// append executable path
			for ( int i = 0; i < strlen(executable_path); i++ )
			{
				version_path[i] = executable_path[i];
			}

			// find 'hykernel/' , store it in pos
			int hykernel_pos = *(strstr(executable_path, "hykernel/"));
			hykernel_pos += strlen("hykernel/");
			version_path[hykernel_pos] = '\x00';
		}
		break;

		case help:
		{
			char help_command[128];
			snprintf(help_command, 128, g_hykernel_directory, "cat %s | less");
			printf("help command buffer: %s\n", help_command);
			system(help_command);
		}
		break;
	}
}
