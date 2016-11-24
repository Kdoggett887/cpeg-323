#include <stdio.h>

int main(){
    int *p;
    int var = 5;
    p = &var;
    
    printf("%i \n", *p);

    return 0;
}