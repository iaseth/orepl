#include "orepl.h"

#include "orepl_lexer.h"
#include "orepl_commands.h"

#include <stdio.h>
#include <string.h>



void
orepl ()
{
	char input[OREPL_MAX_INPUT_LENGTH] = "";
	struct OreplTokenList *token_list = NULL;

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
			token_list = orepl_get_tokens(input);
			//printf("%d tokens found.\n", token_list->number_of_tokens);

			struct OreplToken *token = token_list->first_token;
			while (token != NULL) {
				if (token->ch == 0) {
					printf("Token #x \"%s\"\n", token->text);
				} else {
					printf("Token #x '%c'\n", token->ch);
				}

				token = token->next;
			}
			token_list = orepl_free_tokens(token_list);
		}
	}
	printf("%s\n", OREPL_FAREWELL_TEXT);
}


