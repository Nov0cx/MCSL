#include "Parser.h"

#include <stdlib.h>
#include <string.h>

AST* ast_new(AST* head, ASTType type)
{
    AST* ast = (AST*)malloc(sizeof(AST));
    ast->head = head;
    ast->children = list_new();
    ast->type = type;
    return ast;
}

Parser *parser_new(List *tokens)
{
    Parser *parser = (Parser*)malloc(sizeof(Parser));
    parser->tokens = tokens;
    parser->position = 0;
    return parser;
}

void parser_free(Parser *parser)
{
    free(parser);
}

Token* parser_next_token(Parser* parser)
{
    Token* token = list_get(parser->tokens, parser->position);
    parser->position++;
    return token;
}

AST *parser_parse(Parser *parser)
{
    AST* head = ast_new(0, AST_BLOCK);
    Token* token = parser_next_token(parser);
    while (token->type != TOKEN_EOF)
    {
        switch (token->type)
        {
            case TOKEN_WORD:
            {
                if (strcmp(token->data, "fn") == 0)
                {
                    printf("Found function definition");
                }

                break;
            }
            default:
            MCSL_ERROR_AT_TOKEN(token, "[Parser] Token not implemented: '%s'", token_to_string(token));
        }
        token = parser_next_token(parser);
    }

    return head;
}
