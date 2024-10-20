#include <stdio.h>
#include <stdlib.h>

void run_command(enum command current_command)
{
	switch(current_command)
	{
		case list:
		{
		}
		break;

		case sanity_check:
		{
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
