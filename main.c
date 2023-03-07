#include <stdio.h>
#include <string.h>
#include <stdbool.h>


// 可変個の引数に対応していない
struct Argment{
    bool exists;
    char value[128];
};

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