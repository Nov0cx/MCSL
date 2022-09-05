#ifndef MCSL_TOKEN_H
#define MCSL_TOKEN_H

typedef enum {
    TOKEN_WORD,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_LBRACE,
    TOKEN_RBRACE,
    TOKEN_COLON,
    TOKEN_COMMA,
    TOKEN_SEMICOLON,
    TOKEN_ARROW,
    TOKEN_EQUAL,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_MULTIPLY,
    TOKEN_DIVIDE,
    TOKEN_NUMBER,
    TOKEN_STRING,
    TOKEN_EOF
} TokenType;

typedef struct {
    TokenType type;
    char* data;
    int line, column;
} Token;

Token* token_new(TokenType type, char* data, int line, int column);
void token_free(Token* token);
char *token_to_string(Token* token);

#endif //MCSL_TOKEN_H
