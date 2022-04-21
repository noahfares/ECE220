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

int inputBuffer[Input_Local_BUFFER__SIZE] = {0};
int outputBuffer[Output_BUFFER_SIZE] = {0};

int get_value(){
    static int pointer=0;
    long long dataX[]={\
               0x804010501030300,\
               0x503000102000C05,\
               0x106040504030201,\
               0x2D0A050605040302,\
               0x22000509334E1621,\
               0x1010101010A0215,\
               0x6401000101010101,\
               0x606060606060804,\
               0x203040505030606,\
               0x3020102010A0501,\
               0x401010201020102,\
               0x7FF7B7E5A6FF};

    char* data=(char*)dataX;
    return (int)(data[pointer++]);
}

int submit_results(int* answer)
{
    static int pointer=0;
    static int testCase=0;
    long long dataX[]={\
                    0x1020C0101010100,\
                    0x601020402010300,\
                    0xA010204060205,\
                    0x103060602046401,\
                    0x401010505020502};

    char* data=(char*)dataX;
    int end=data[pointer+1]+pointer+2;
    int index;
    int output=0;
    int tempPointer=pointer;
    testCase++;
    for(index=0;pointer<end;pointer++,index++) {
        if (answer[index]!=((int)(data[pointer]))) {
            output=1;
        }
    }
    if(output==0) {
        printf("\nTest case %d: Successful\n",testCase);
    } else {
        printf("\nTest case %d: Failed\n",testCase);
        printf("-----------------------------------\n");
        printf("| %-15s| %-15s|\n","Correct Answer","Your Answer");
        printf("-----------------------------------\n");
        for(index=0;tempPointer<end;tempPointer++,index++) {
            printf("| %-15d| %-15d|\n",((int)(data[tempPointer])),answer[index]);
        }
        printf("-----------------------------------\n");
    }
    return output;
}

int reading() {
    int data = get_value();

    if (data == -1) {
        return -1;
    }

    inputBuffer[0] = data;
    inputBuffer[1] = get_value();

    int counter = 0;

    while (counter++ <= inputBuffer[1]) {
        inputBuffer[2 + counter] = get_value();
    }
    return 0;
}

void transferringTOlocal(int localBuffer[]) {
    int counter = 0;

    while (counter < inputBuffer[1]+2){
        localBuffer[counter] = inputBuffer[counter];
        counter++;
    }
}

void processing(int localBuffer[]) {
    int min = localBuffer[2], max = localBuffer[2]; // sets the inital value to one of the numbers in the buffers
    int odd = 0, even = 0;

    switch (localBuffer[0])
    {

        case MIN:
            for (int i = 1; i < inputBuffer[1]; i++) // we start from 2 because the first two values of the array are not part of the processing.
            {
                if (min > localBuffer[i]) // check if the previous min value is greater than the the current value within the array, if it is that means that the current value in the array is smaller
                    min = localBuffer[i];
            }

            localBuffer[2] = min; // storing the lowest value in the third index of the array
            localBuffer[1] = 1;   // count
            break;

        case MAX:
            for (int i = 1; i < inputBuffer[1]; i++)
            {
                if (max <= localBuffer[i]) // cheacks to see if the max value is smaller than the current value in the array, if max is less, that means that there is a larger value and it will store it in max variable
                    max = localBuffer[i];
            }

            localBuffer[2] = max; // storing
            localBuffer[1] = 1;   // count
            break;

        case ODD:
            for (int i = 1; i < inputBuffer[1]; i++)
            {
                if (localBuffer[i] % 2 != 0) // checks to see if there is a remainder when dividing by two, if there is we know the value is odd
                    odd++;
            }

            localBuffer[2] = odd; // storing
            localBuffer[1] = 1;   // count
            break;

        case EVEN:
            for (int i = 1; i < inputBuffer[1]; i++)
            {
                if (localBuffer[i] % 2 == 0) // checks to see if dividing by two does not give a remainder
                    even++;
            }

            localBuffer[2] = even; // storing
            localBuffer[1] = 1;
            break;

        case MINMAX:
            for (int i = 1; i < inputBuffer[1]; i++)
            {
                if (min >= localBuffer[i])
                    min = localBuffer[i];
                if (max <= localBuffer[i])
                    max = localBuffer[i];
            }

            localBuffer[3] = max;
            localBuffer[2] = min;
            localBuffer[1] = 2;
            break;

        case ODDEVEN:
            for (int i = 1; i < inputBuffer[1]; i++)
            {
                if (localBuffer[i] % 2 != 0)
                    odd++;
                if (localBuffer[i] % 2 == 0)
                    even++;
            }

            localBuffer[3] = even;
            localBuffer[2] = odd;
            localBuffer[1] = 2;
            break;
    }
}


void transferringFROMlocal(int localBuffer[]) {

    int counter = 0;

    while (counter <= inputBuffer[1]) {
        outputBuffer[counter] = localBuffer[counter];
    }
}

void submitting() {

    int i = submit_results(outputBuffer);

    if ( i == 0){
        printf("Correct\n");
    } else {
        printf("Incorrect\n");
    }

    for (int j = 0; j <= Input_Local_BUFFER__SIZE; j++) {
        inputBuffer[j] = 0;
        outputBuffer[j] = 0;
    }
}
