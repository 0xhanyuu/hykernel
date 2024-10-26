#include <stdio.h>
#include <stdlib.h>
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
	char first_character = argv[1][0];
	char second_character = argv[1][1];

	switch(first_character)
	{
		case 'n':
		return nop;
		break;

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
