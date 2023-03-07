#ifndef ARG_H
#define ARG_H

#include <stdbool.h>

struct Argment{
    bool exists;
    char value[128];
};

void parse_arg(struct Argment* arg, char key[], int argc, char* argv[]);

#endif /* ARG_H */