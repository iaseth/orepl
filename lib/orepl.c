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

	while (strcmp(input, OREPL_COMMAND_EXIT)) {
		printf("%s\n", OREPL_WELCOME_TEXT);
		printf("=> ");
		scanf("%s", input);
	}
	printf("%s\n", OREPL_FAREWELL_TEXT);
}


