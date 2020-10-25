#include "orepl.h"

#include <stdio.h>
#include <string.h>

void
orepl ()
{
	char input[OREPL_MAX_INPUT_LENGTH] = "";

	while (strcmp(input, "exit")) {
		printf("Welcome to Orepl!\n");
		printf("=> ");
		scanf("%s", input);
	}
}


