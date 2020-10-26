#ifndef OREPL_LEXER_H_IS_INCLUDED
#define OREPL_LEXER_H_IS_INCLUDED

#include "orepl_token_types.h"



struct OreplToken {
	enum OreplTokenType token_type;

	struct OreplToken *next;
	struct OreplToken *prev;

	char ch;
	char *text;
};

struct OreplTokenList {
	int number_of_tokens;
	struct OreplToken *first_token;
	struct OreplToken *last_token;
};

struct OreplTokenList* orepl_get_tokens (char *code);
struct OreplTokenList* orepl_free_tokens (struct OreplTokenList *token_list);



#endif