#include "orepl.h"

#include <stdio.h>
#include <string.h>

char *OREPL_WELCOME_TEXT = "Welcome to Orepl!";
char *OREPL_FAREWELL_TEXT = "Bye.";

char *OREPL_COMMAND_EXIT = "exit";



void
orepl ()
{
	char input[OREPL_MAX_INPUT_LENGTH] = "";

	printf("%s\n", OREPL_WELCOME_TEXT);
	while (1) {
		printf("=> ");
		scanf("%s", input);
		if (strcmp(input, OREPL_COMMAND_EXIT) == 0) {
			break;
		}
	}
	printf("%s\n", OREPL_FAREWELL_TEXT);
}


