#include <stdio.h>
#include <string.h>
#include <stdbool.h>


// 可変個の引数に対応していない
struct Argment{
    char key[64];
    bool exists;
    char value[128];
};

int parse_arg(struct Argment* arg, int argc, char* argv[]){
    arg->exists = false;

    for(int i = 0; i < argc ; i++){
        if(strcmp(argv[i],arg->key) != 0) continue;
        arg->exists = true;

        if( i + 1 == argc){
            return -1;
        }

        if(strncmp(argv[i + 1],"-",1) == 0 || strncmp(argv[i + 1],"--",2) == 0 ){
            return -1;
        }

        strcpy(arg->value,argv[i + 1]);
        return 0;
    }
    return -1;
}

int main(int argc, char* argv[]){
    struct Argment arg;
    strcpy(arg.key,"-p");
    parse_arg(&arg,argc,argv);

    printf("print: %s\n",arg.value);

    return 0;
}