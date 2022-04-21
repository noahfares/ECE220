#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    char newString[100];
    int stringCounter = 0;

    printf("Please enter a string:\n");
    fgets(input, 100, stdin);

    int zero = 0, one = 0, two = 0, three = 0, four = 0, five = 0, six =0, seven = 0, eight = 0, nine = 0;

    for (int count = 0; count < strlen(input); count++){
        switch(input[count]){
            case '0':
                zero++;
                break;
            case '1':
                one++;
                break;
            case '2':
                two++;
                break;
            case '3':
                three++;
                break;
            case '4':
                four++;
                break;
            case '5':
                five++;
                break;
            case '6':
                six++;
                break;
            case '7':
                seven++;
                break;
            case '8':
                eight++;
                break;
            case '9':
                nine++;
                break;
            default:
                newString[stringCounter++] = input[count];
        }
    }
    if (zero > 0) {
        printf("Digit 0: Occurence: %d\n", zero);
    }
    if (one > 0) {
        printf("Digit 1: Occurence: %d\n", one);
    }
    if (two > 0) {
        printf("Digit 2: Occurence: %d\n", two);
    }
    if (three > 0) {
        printf("Digit 3: Occurence: %d\n", three);
    }
    if (four > 0) {
        printf("Digit 4: Occurence: %d\n", four);
    }
    if (five > 0) {
        printf("Digit 5: Occurence: %d\n", five);
    }
    if (six > 0) {
        printf("Digit 6: Occurence: %d\n", six);
    }
    if (seven > 0) {
        printf("Digit 7: Occurence: %d\n", seven);
    }
    if (eight > 0) {
        printf("Digit 8: Occurence: %d\n", eight);
    }
    if (nine > 0) {
        printf("Digit 9: Occurence: %d\n", nine);
    }

    printf("\nEntered array without digits:\n%s", newString);
    return 0;
}