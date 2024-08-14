#include <stdio.h>
#include <stdlib.h>

void print_choice_table()
{
	printf("%s\n", "hykernel list			0");
	printf("%s\n", "hykernel set			1");
	printf("%s\n", "hykernel show			2");
	printf("%s\n", "hykernel sanity_check		3");
	printf("%s\n", "hykernel version		4");
}

int main()
{
	int choice;

	printf("%s\n", "choose: ");
	print_choice_table();

	scanf("%d", &choice);
	switch(choice)
	{
		case 0:
		system("hykernel list");
		break;

		case 1:
		system("hykernel set");
		break;

		case 2:
		system("hykernel show");
		break;

		case 3:
		system("hykernel sanity_check");
		break;

		case 4:
		system("hykernel version");
		break;

		default:
		printf("%s\n", "invalid option!");
		printf("%s\n", "terminating program ...");
		return EXIT_FAILURE;
		break;
	}

	return 0;
}

/*
TODO:
hykernel list			[]
hykernel set			[]
hykernel show			[]
hykernel sanity_check	[]
hykernel version		[]
hykernel help			[]

implement pretty menu with virtual term seq.
*/
