#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

    char enter[50];
    char letter [50];
    char numb [50];
    printf("Please input a string of digits and characters:\n");
    fgets(enter, 50, stdin);
    int counter1 = 0;
    int counter2 = 0;
    for (int i = 0; i < strlen(enter); i++) {
        if (isalpha(enter[i])==1 || isalpha(enter[i])==2) {
            letter[counter1] = enter[i];
            counter1++;

        } else {
            numb[counter2] = enter[i];
            counter2++;
        }
    }

    if (strlen(numb) > strlen(letter)) {
        printf("The longer string is: %ssize: %d", numb, counter2 - 1);
    } else {
        printf("the longer string is: %s\nsize: %d", letter, counter1);
    }

    return 0;
}