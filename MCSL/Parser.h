#ifndef MCSL_PARSER_H
#define MCSL_PARSER_H

#include "Lexer.h"
#include "utils/List.h"
#include "utils/Error.h"

typedef enum {
    AST_ASSIGNMENT,
    AST_EXPRESSION,
    AST_FUNCTION_CALL,
    AST_FUNCTION_DEFINITION,
    AST_IF,
    AST_NUMBER,
    AST_RETURN,
    AST_VALUE,
    AST_VARIABLE_DEFINITION,
    AST_VARIABLE_REFERENCE,
    AST_BLOCK
} ASTType;

typedef struct AST AST;

struct AST {
    AST* head;
    List* children;
    ASTType type;
};

AST *ast_new(AST* head, ASTType type);

typedef struct {
    List* tokens;
    int position;
} Parser;

Parser* parser_new(List* tokens);
void parser_free(Parser* parser);

Token* parser_next_token(Parser* parser);
AST* parser_parse(Parser* parser);
AST* parser_parse_function(Parser* parser);

#endif //MCSL_PARSER_H
