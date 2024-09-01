#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <hykernel.h> // functions

char g_hykernel_directory[128];
char executable_path[128];
ssize_t bytes_read;

char * command_list[6] = {
				"list", "set",
				"show", "sanity_check",
				"version", "help"};

enum command
{
	nop = 0,

	list,
	set,
	show,
	sanity_check,
	version,
	help,
};

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

int main(int argc, char **argv)
{
	enum command current_command;

	// allocate memory for executable_path
	executable_path = (char *)malloc(128 * sizeof(char));
	bytes_read = readlink("/proc/self/exe", executable_path, 128-1);

	// append null term char
	executable_path[bytes_read] = '\x00';

	file_handling(argc, argv);

	current_command = get_command(argc, argv);
	run_command(current_command);

	free(executable_path);
	return 0;
}
