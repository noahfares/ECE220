#define MIN     0
#define MAX     1
#define ODD     2
#define EVEN    3
#define MINMAX  4
#define ODDEVEN 5

#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "buffer.h"

int main(void) {

    int isData;
    int localBuffer[Input_Local_BUFFER__SIZE]= {0};


    isData = reading();

    while (isData !=-1) {

        transferringTOlocal(localBuffer);
        processing(localBuffer);
        transferringFROMlocal(localBuffer);
        submitting();
        for (int i = 0; i < Input_Local_BUFFER__SIZE; i++) {
            localBuffer[i] = 0;
        }
        isData = reading();
        printf("1");
    }
    return 0;
}






