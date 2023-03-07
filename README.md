# parse arg

```
curl https://raw.githubusercontent.com/sei-12/parse-arg/main/arg.c > arg.c
curl https://raw.githubusercontent.com/sei-12/parse-arg/main/arg.h > arg.h
```

## 使い方
main.c
```c
#include <stdio.h>
#include "arg.h"

int main(int argc, char* argv[]){
    struct Argment arg;  parse_arg(&arg,"-p",argc,argv);

    if(arg.exists){
        printf("print: %s\n",arg.value);
    }

    return 0;
}
```
### 実行してみる
```
./main -p abc
```
>print: abc

<br>

```
./main
```
何も出力されない

<br>

```
./main -p
```
>print:

<br>

```
./main -p -a
```
>print:

指定したキーワード(ここでは-p)の次の引数が - または -- で始まる場合、```Argment.value```には "" が入ります

<br>