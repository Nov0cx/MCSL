#include <stdio.h>
#include <stdlib.h>
#include "MCSL/MCSL.h"

char* ReadFile(char *filename)
{
    char *buffer = NULL;
    int string_size, read_size;
    FILE *handler = fopen(filename, "r");

    if (handler)
    {
        // Seek the last byte of the file
        fseek(handler, 0, SEEK_END);
        // Offset from the first to the last byte, or in other words, filesize
        string_size = ftell(handler);
        // go back to the start of the file
        rewind(handler);

        // Allocate a string that can hold it all
        buffer = (char*) malloc(sizeof(char) * (string_size + 1) );

        // Read it all in one operation
        read_size = fread(buffer, sizeof(char), string_size, handler);

        // fread doesn't set it so put a \0 in the last position
        // and buffer is now officially a string
        buffer[read_size] = '\0';

        // Always remember to close the file.
        fclose(handler);
    }

    return buffer;
}

int main()
{
    char* file = ReadFile("Example/main.mcsl");

    printf("%s\n", file);
    printf("----------------\n");

    Lexer* lexer = lexer_new(file);
    printf("%s\n", lexer->source);
    List* tokens = lexer_tokenize(lexer);

    printf("%d tokens\n", tokens->size);

    for (int i = 0; i < tokens->size; i++)
    {
        Token* token = list_get(tokens, i);
        printf("%s\n", token_to_string(token));
    }

    printf("----------------\n");
    AST* ast = parser_parse(parser_new(tokens));

    return 0;
}
