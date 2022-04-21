/*
Noah Fares
1660075 
Lab 1
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main()
{

    //This is defining the variable we are going to need for the program to work
    int max = 0;
    int min = 0;
    int program_guess, counter, user_pick;

    //Initial statements to the user
    printf("First, think of a number...\n");
    printf("Now I need you to give me a range (max and min) around the value you chose:\n");

    //Retrieving the max of the range
    printf("Max:");
    scanf("%d", &max);

    //Retrieving the min of the range
    printf("Min: ");
    scanf("%d", &min);

    while (min > max)
    {
        printf("\nThe min is larger than the max, please enter two new values:\n");

        printf("Max:");
        scanf("%d", &max);

        printf("Min: ");
        scanf("%d", &min);
    }

    //First guess
    program_guess = (max + min) / 2;
    counter = 1;
    printf("\nIs %d your number?\n", program_guess);

    //User input
    printf("1. TOO LARGE\n2. TOO SMALL\n3. FOUND\n \nEnter: ");
    scanf("%d", &user_pick);

    //Continue the guessing using if statements
    while (user_pick != 3)
    {

        //If guess is too large
        if (user_pick == 1)
        {
            max = program_guess - 1;
            program_guess = (max + min) / 2;
            counter = counter + 1;
            printf("\nIs %d your number?\n", program_guess);
            printf("1. TOO LARGE\n2. TOO SMALL\n3. FOUND\n \nEnter: ");
            scanf("%d", &user_pick);
        }

        //If guess is too small
        if (user_pick == 2)
        {
            min = program_guess + 1;
            program_guess = (max + min) / 2;
            counter = counter + 1;
            printf("\nIs %d your number?\n", program_guess);
            printf("1. TOO LARGE\n2. TOO SMALL\n3. FOUND\n \nEnter: ");
            scanf("%d", &user_pick);
        }

        //Just in case any values other than 1, 2, or 3 were entered, this will bring the code back on path to the start of the while
        if (user_pick != 1 && user_pick !=2 && user_pick != 3)
        {
            printf("\nPlease select one of these options:\n1. TOO LARGE\n2. TOO SMALL\n3. FOUND\n \nEnter: ");
            scanf("%d", &user_pick);
        }
    }

    //For when the code finally guesses right. There are two just to fix the grammar between try and tries
    if (user_pick == 3, counter == 1)
    {
        printf(" \nFound it!\nThe number was %d and it took me %d try\nThanks for playing!!!\n \n", program_guess, counter);
        printf("Code by Noah Fares\nStudent ID: 1660075\n");
    }

    if (user_pick == 3, counter != 1)
    {
        printf(" \nFound it!\nThe number was %d and it took me %d tries\nThanks for playing!!!\n \n", program_guess, counter);
        printf("Code by Noah Fares\nStudent ID: 1660075\n");
    }

    return 0;
}