#include <stdio.h>
#include <string.h>

int get_arg(char* opt,char* buf,int argc, char* argv[]){
    for(int i = 0; i<argc ; i++){
        if(strcmp(argv[i],opt) == 0){
            if(i + 1 == argc){
                printf("引数が足りません");
                continue;
            }
            strcpy(buf,argv[i + 1]);
            return 0;
        }
    }

    return -1;
}

int main(int argc, char* argv[]){

    char test[32];
    get_arg("-p",test,argc,argv);
    printf("print: %s\n",test);

    return 0;
}