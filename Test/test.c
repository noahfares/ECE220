#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
    char name[20] = "Hello";
    printf("%d", sizeof(name));
    printf("%d", strlen(name));  

    return 0;
}