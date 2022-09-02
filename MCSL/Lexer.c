#include "Lexer.h"

#include <stdlib.h>
#include <string.h>

Lexer *lexer_new(char *source)
{
    Lexer *lexer = malloc(sizeof(Lexer));
    lexer->source = source;
    lexer->position = 0;
    lexer->line = 1;
    lexer->column = 1;
    return lexer;
}

void lexer_free(Lexer *lexer)
{
    free(lexer);
}

List *lexer_tokenize(Lexer *lexer)
{
    List *tokens = list_new();

    while (lexer->position < strlen(lexer->source))
    {
        Token *token = lexer_next_token(lexer);
        if (token->type != TOKEN_EOF)
            list_add(tokens, token);
        else return tokens;
    }

    return tokens;
}

Token *lexer_next_token(Lexer *lexer)
{
    switch (lexer->source[lexer->position])
    {
        case ' ':
        case '\t':
        case '\r':
        case '\n':
            lexer_skip_whitespace(lexer);
            return lexer_next_token(lexer);
        case '+':
        {
            Token *t = token_new(TOKEN_PLUS, "+");
            lexer->position++;
            return t;
        }
        case '-':
        {
            Token *t = token_new(TOKEN_MINUS, "-");
            lexer->position++;
            return t;
        }
        case '*':
        {
            Token *t = token_new(TOKEN_MULTIPLY, "*");
            lexer->position++;
            return t;
        }
        case '/':
        {
            Token *t = token_new(TOKEN_DIVIDE, "/");
            lexer->position++;
            return t;
        }
        case '(':
        {
            Token *t = token_new(TOKEN_LPAREN, "(");
            lexer->position++;
            return t;
        }
        case ')':
        {
            Token *t = token_new(TOKEN_RPAREN, ")");
            lexer->position++;
            return t;
        }
        case '{':
        {
            Token *t = token_new(TOKEN_LBRACE, "{");
            lexer->position++;
            return t;
        }
        case '}':
        {
            Token *t = token_new(TOKEN_RBRACE, "}");
            lexer->position++;
            return t;
        }
        case ';':
        {
            Token *t = token_new(TOKEN_SEMICOLON, ";");
            lexer->position++;
            return t;
        }
        case ',':
        {
            Token *t = token_new(TOKEN_COMMA, ",");
            lexer->position++;
            return t;
        }
        case ':':
        {
            Token *t = token_new(TOKEN_COLON, ":");
            lexer->position++;
            return t;
        }
        case '=':
        {
            Token *t = token_new(TOKEN_EQUAL, "=");
            lexer->position++;
            return t;
        }
            /*case '!':
                return token_new(TOKEN_BANG, "!");
            case '<':
                return token_new(TOKEN_LESS_THAN, "<");
            case '>':
                return token_new(TOKEN_GREATER_THAN, ">");*/
        case '"':
            return lexer_string(lexer);
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return lexer_number(lexer);
        case '\0':
        {
            Token *t = token_new(TOKEN_EOF, "EOF");
            lexer->position++;
            return t;
        }
        default:
            return lexer_identifier(lexer);
    }
}

void lexer_skip_whitespace(Lexer *lexer)
{
    while (lexer->source[lexer->position] == ' ' || lexer->source[lexer->position] == '\t' ||
           lexer->source[lexer->position] == '\r' || lexer->source[lexer->position] == '\n')
    {
        if (lexer->source[lexer->position] == '\n')
        {
            lexer->line++;
            lexer->column = 1;
        } else
        {
            lexer->column++;
        }
        lexer->position++;
    }
}

Token *lexer_string(Lexer *lexer)
{
    char *string = malloc(sizeof(char));
    int position = lexer->position;
    while (lexer->source[position] != '"')
    {
        string = realloc(string, sizeof(char) * (position - lexer->position + 2));
        string[position - lexer->position] = lexer->source[position];
        position++;
    }
    string[position - lexer->position] = '\0';
    lexer->position = position + 1;
    return token_new(TOKEN_STRING, string);
}

Token *lexer_number(Lexer *lexer)
{
    char *number = malloc(sizeof(char));
    int position = lexer->position;
    while (isdigit(lexer->source[position]))
    {
        number = realloc(number, sizeof(char) * (position - lexer->position + 2));
        number[position - lexer->position] = lexer->source[position];
        position++;
    }
    number[position - lexer->position] = '\0';
    lexer->position = position;
    return token_new(TOKEN_NUMBER, number);
}

Token *lexer_identifier(Lexer *lexer)
{
    char *identifier = malloc(sizeof(char));
    int position = lexer->position;
    identifier = realloc(identifier, sizeof(char) * (position - lexer->position + 2));
    identifier[position - lexer->position] = lexer->source[position];
    position++;
    while (isalpha(lexer->source[position]) || isdigit(lexer->source[position]))
    {
        identifier = realloc(identifier, sizeof(char) * (position - lexer->position + 2));
        identifier[position - lexer->position] = lexer->source[position];
        position++;
    }
    identifier[position - lexer->position] = '\0';
    lexer->position = position;
    return token_new(TOKEN_WORD, identifier);
}