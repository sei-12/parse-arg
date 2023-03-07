#include <stdbool.h>
#include <string.h>
#include "arg.h"

void parse_arg(struct Argment* arg, char key[], int argc, char* argv[]){
    arg->exists = false;

    for(int i = 0; i < argc ; i++){
        if(strcmp(argv[i],key) != 0) continue;
        arg->exists = true;

        if( i + 1 == argc){
            break;
        }

        if(strncmp(argv[i + 1],"-",1) == 0 || strncmp(argv[i + 1],"--",2) == 0 ){
            break;
        }

        strcpy(arg->value,argv[i + 1]);
        return;
    }
    strcpy(arg->value,"");
    return;

}