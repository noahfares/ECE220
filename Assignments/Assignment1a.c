/*
Noah Fares
1660075 
Assignment 1a
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    //the two variables used for storing the users input
    int user_input1, user_input2;

    while (user_input1 >= 0 || user_input2 >= 0)
    {
        //we can determine which of the two values are the larger and smaller one and we can store those into these variables for ease
        int max = 0, min = 0, i, sum = 0; 

        printf("\nPlease input two numbers:\n");
        printf("1:");
        scanf("%d", &user_input1);

        printf("2:");
        scanf("%d", &user_input2);

        if (user_input1 == user_input2)
        {
            printf("\nPlease start over again and enter two different numbers\n");
            return 0;
        }

        if (user_input1 < 0 || user_input2 < 0)
        {
            printf("\nPlease start over again and enter postitve numbers\n");
            return 0;
        }

        //this if statement will store the inputed values into the max and min variables
        if (user_input1 > user_input2)
        {
            max = user_input1;
            min = user_input2;
            i = min;
        }
        else
        {
            max = user_input2;
            min = user_input1;
            i = min;
        }

        while (i <= max)
        {
            sum += i;
            i++;
        }

        printf("\nThe result is %d.\n", sum);
    }

    return 0;
}