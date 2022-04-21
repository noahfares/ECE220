#include <stdio.h>
#define ARR_MAX 50

int main(void)
{
    char array[ARR_MAX] = "What a nice day today.";
    char arrayINV[ARR_MAX] = {0};
    int i = 0;
    int j = 22;

    while( i++ < 22){
        arrayINV[j--] = array[i];
    }

    printf("inverted string: %s", arrayINV);

    return 0;
}