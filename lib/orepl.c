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
			char *command = input + 1;
			if (strcmp(command, OREPL_COMMAND_BREAK) == 0) {
				printf("Lets break up.\n");
			} else if (strcmp(command, OREPL_COMMAND_EXIT) == 0) {
				break;
			} else if (strcmp(command, OREPL_COMMAND_HELP) == 0) {
				printf("Help yourself.\n");
			} else if (strcmp(command, OREPL_COMMAND_LOAD) == 0) {
				printf("Loading ...\n");
			} else if (strcmp(command, OREPL_COMMAND_SAVE) == 0) {
				printf("Saving ...\n");
			} else if (strcmp(command, OREPL_COMMAND_VERSION) == 0) {
				printf("Orepl is on 0.1.0 (electric-guitar).\n");
			} else {
				printf("Not a command: '%s'\n", input);
			}
		} else {
			printf("Command: '%s'\n", input);
		}
	}
	printf("%s\n", OREPL_FAREWELL_TEXT);
}


