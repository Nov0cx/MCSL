#ifndef MCSL_ERROR_H
#define MCSL_ERROR_H

#include <stdio.h>

#ifndef MCSL_ERROR_SINK
#define MCSL_ERROR_SINK stderr
#endif

#define MCSL_ERROR(...)  \
    fprintf(MCSL_ERROR_SINK, __VA_ARGS__); \
    fprintf(MCSL_ERROR_SINK, "\n")

#define MCSL_ERROR_AT(line, column, ...)  \
    fprintf(MCSL_ERROR_SINK, "Error at line %d:%d: ", line, column); \
    fprintf(MCSL_ERROR_SINK, __VA_ARGS__); \
    fprintf(MCSL_ERROR_SINK, "\n")

#define MCSL_ERROR_AT_TOKEN(token, ...)  \
    MCSL_ERROR_AT(token->line, token->column, __VA_ARGS__)

#define MCSL_FAIL(...)  \
    MCSL_ERROR(__VA_ARGS__); \
    exit(1)

#endif //MCSL_ERROR_H
