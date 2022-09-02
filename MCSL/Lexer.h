#ifndef MCSL_LEXER_H
#define MCSL_LEXER_H

#include "Token.h"
#include "utils/List.h"

typedef struct {
    char* source;
    int position;
    int line;
    int column;
} Lexer;

Lexer* lexer_new(char* source);
void lexer_free(Lexer* lexer);

List* lexer_tokenize(Lexer* lexer);
Token* lexer_next_token(Lexer* lexer);
void lexer_skip_whitespace(Lexer* lexer);
Token* lexer_string(Lexer* lexer);
Token* lexer_number(Lexer* lexer);
Token* lexer_identifier(Lexer* lexer);

#endif //MCSL_LEXER_H
