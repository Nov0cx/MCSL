#include "Token.h"
#include <stdlib.h>

Token *token_new(TokenType type, char *data)
{
    Token *token = malloc(sizeof(Token));
    token->type = type;
    token->data = data;
    return token;
}

void token_free(Token *token)
{
    free(token->data);
    free(token);
}

char *token_to_string(Token *token)
{
    char *string = malloc(sizeof(char) * (strlen(token->data) + 1));
    strcpy(string, token->data);
    return string;
}