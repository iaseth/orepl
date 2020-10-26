#include "orepl_lexer.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct OreplTokenList *
orepl_get_tokens (char *code)
{
	int index = 0;
	char ch = code[index];

	struct OreplTokenList *token_list = malloc(sizeof(struct OreplTokenList));
	token_list->number_of_tokens = 0;
	token_list->first_token = NULL;
	token_list->last_token = NULL;

	struct OreplToken *current_token = NULL;
	int current_token_length = 1;

	while (ch != '\0') {
		if (current_token == NULL) {
			current_token = malloc(sizeof(struct OreplToken));
			current_token->token_type = OREPL_TOKEN_NONE;
			current_token->next = NULL;
			current_token->prev = NULL;
			current_token->text = NULL;
			current_token->ch = '\0';
			current_token_length = 1;
		}

		switch (ch) {

			case '(':
				current_token->token_type = OREPL_TOKEN_PAREN_LEFT;
				break;
			case ')':
				current_token->token_type = OREPL_TOKEN_PAREN_RIGHT;
				break;


			case '{':
				current_token->token_type = OREPL_TOKEN_BRACE_LEFT;
				break;
			case '}':
				current_token->token_type = OREPL_TOKEN_BRACKET_RIGHT;
				break;


			case '[':
				current_token->token_type = OREPL_TOKEN_BRACKET_LEFT;
				break;
			case ']':
				current_token->token_type = OREPL_TOKEN_BRACKET_RIGHT;
				break;


			case ',':
				current_token->token_type = OREPL_TOKEN_COMMA;
				break;
			case '.':
				current_token->token_type = OREPL_TOKEN_FULL_STOP;
				break;


			case '<':
				current_token->token_type = OREPL_TOKEN_LESS_THAN_SIGN;
				break;
			case '>':
				current_token->token_type = OREPL_TOKEN_GREATER_THAN_SIGN;
				break;


			case ';':
				current_token->token_type = OREPL_TOKEN_SEMI_COLON;
				break;
			case ':':
				current_token->token_type = OREPL_TOKEN_COLON;
				break;


			case '+':
				current_token->token_type = OREPL_TOKEN_PLUS;
				break;
			case '-':
				current_token->token_type = OREPL_TOKEN_MINUS;
				break;


			case '~':
				current_token->token_type = OREPL_TOKEN_TILDE_SIGN;
				break;
			case '!':
				current_token->token_type = OREPL_TOKEN_EXCLAMATION_MARK;
				break;
			case '@':
				current_token->token_type = OREPL_TOKEN_AT_SIGN;
				break;
			case '#':
				current_token->token_type = OREPL_TOKEN_HASH_SIGN;
				break;
			case '$':
				current_token->token_type = OREPL_TOKEN_DOLLAR_SIGN;
				break;


			case '%':
				current_token->token_type = OREPL_TOKEN_PERCENT_SIGN;
				break;
			case '^':
				current_token->token_type = OREPL_TOKEN_CARET_SIGN;
				break;
			case '&':
				current_token->token_type = OREPL_TOKEN_AMPERSAND_SIGN;
				break;
			case '*':
				current_token->token_type = OREPL_TOKEN_ASTERISK;
				break;


			case '_':
				current_token->token_type = OREPL_TOKEN_UNDERSCORE;
				break;
			case '=':
				current_token->token_type = OREPL_TOKEN_EQUAL_SIGN;
				break;


			case '?':
				current_token->token_type = OREPL_TOKEN_QUESTION_MARK;
				break;
			case '/':
				current_token->token_type = OREPL_TOKEN_SLASH;
				break;
			case '\\':
				current_token->token_type = OREPL_TOKEN_BACKSLASH;
				break;
			case '|':
				current_token->token_type = OREPL_TOKEN_PIPE;
				break;

			case '"':
				break;

			case ' ':
			case '\t':
			case '\n':
				break;

			default:
				if (code[index] == 'c'
					&& code[index+1] == 'o' && code[index+2] == 'n'
					&& code[index+3] == 's' && code[index+4] == 't'
					&& !isalnum(code[index+5])
				) {
					current_token->token_type = OREPL_TOKEN_CONST;
					current_token_length = 5;
				} else if (code[index] == 'l'
					&& code[index+1] == 'e' && code[index+2] == 't'
					&& !isalnum(code[index+3])
				) {
					current_token->token_type = OREPL_TOKEN_LET;
					current_token_length = 3;
				} else if (code[index] == 't'
					&& code[index+1] == 'r' && code[index+2] == 'u'
					&& code[index+3] == 'e' && !isalnum(code[index+4])
				) {
					current_token->token_type = OREPL_TOKEN_TRUE;
					current_token_length = 4;
				} else if (code[index] == 'f'
					&& code[index+1] == 'a' && code[index+2] == 'l'
					&& code[index+3] == 's' && code[index+4] == 'e'
					&& !isalnum(code[index+5])
				) {
					current_token->token_type = OREPL_TOKEN_FALSE;
					current_token_length = 5;
				} else if (code[index] == 'n'
					&& code[index+1] == 'u' && code[index+2] == 'l'
					&& code[index+3] == 'l' && !isalnum(code[index+4])
				) {
					current_token->token_type = OREPL_TOKEN_NULL;
					current_token_length = 4;
				} else {
					current_token->token_type = OREPL_TOKEN_IDENTIFIER;
					current_token_length = 0;
					char *x = &code[index];
					while (isalnum(*x++)) {
						current_token_length++;
					}
				}
		}

		if (current_token->token_type != OREPL_TOKEN_NONE) {
			if (current_token_length == 1) {
				current_token->ch = ch;
			} else {
				current_token->text = malloc(sizeof(char) * (current_token_length + 1));
				for (int i = 0; i < current_token_length; ++i) {
					current_token->text[i] = code[index + i];
				}
				current_token->text[current_token_length] = '\0';
			}

			if (token_list->number_of_tokens == 0) {
				token_list->first_token = current_token;
				token_list->last_token = current_token;
			} else {
				current_token->prev = token_list->last_token;
				token_list->last_token->next = current_token;
				token_list->last_token = current_token;
			}
			token_list->number_of_tokens++;
			current_token = NULL;
		}

		index += current_token_length;
		ch = code[index];
	}

	if (current_token != NULL) {
		free(current_token);
		current_token = NULL;
	}

	return token_list;
}

struct OreplTokenList *
orepl_free_tokens (struct OreplTokenList *token_list)
{
	if (token_list != NULL) {
		struct OreplToken *token = token_list->first_token;
		while (token != NULL) {
			struct OreplToken *temp_token = token;
			token = token->next;
			free(temp_token);
		}
		free(token_list);
		token_list = NULL;
	}
	return NULL;
}


