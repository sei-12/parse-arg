#include <stdio.h>
#include "arg.h"

int main(int argc, char* argv[]){
    struct Argment arg;  parse_arg(&arg,"-p",argc,argv);
    struct Argment arg2; parse_arg(&arg2,"-a",argc,argv);

    if(arg.exists){
        printf("print: %s\n",arg.value);
    }

    if(arg2.exists){
        printf("arg2\n");
    }

    return 0;
}