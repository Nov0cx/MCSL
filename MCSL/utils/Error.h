#ifndef MCSL_ERROR_H
#define MCSL_ERROR_H

#include <stdio.h>

#ifndef MCSL_ERROR_SINK
#define MCSL_ERROR_SINK stderr
#endif

#define MCSL_ERROR(...) do { \
    fprintf(MCSL_ERROR_SINK, __VA_ARGS__); \
    fprintf(MCSL_ERROR_SINK, "\n");        \
    exit(1);\
} while (0)

#endif //MCSL_ERROR_H
