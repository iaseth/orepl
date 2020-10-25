#include "orepl.h"

#include <stdio.h>
#include <string.h>

char *OREPL_WELCOME_TEXT = "Welcome to Orepl!";
char *OREPL_FAREWELL_TEXT = "Bye.";

char *OREPL_COMMAND_BREAK   = "break";
char *OREPL_COMMAND_EXIT    = "exit";
char *OREPL_COMMAND_HELP    = "help";
char *OREPL_COMMAND_LOAD    = "load";
char *OREPL_COMMAND_SAVE    = "save";
char *OREPL_COMMAND_VERSION = "version";



void
orepl ()
{
	char input[OREPL_MAX_INPUT_LENGTH] = "";

	printf("%s\n", OREPL_WELCOME_TEXT);
	while (1) {
		// the prompt
		printf("=> ");

		fgets(input, OREPL_MAX_INPUT_LENGTH, stdin);
		// remove newline at the end
		int length = strlen(input) - 1;
		input[length] = '\0';

		if (input[0] == '.') {
			if (strcmp(input + 1, OREPL_COMMAND_EXIT) == 0) {
				break;
			} else {
				printf("Not a command: '%s'\n", input);
			}
		} else {
			printf("Command: '%s'\n", input);
		}
	}
	printf("%s\n", OREPL_FAREWELL_TEXT);
}


