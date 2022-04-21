/*
Noah Fares
1660075 
Assignment 1b
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int user_input1 = 0, user_input2 = 0, user_input3 = 0;

    while (user_input1 >= 0 && user_input2 >= 0 && user_input3 >= 0)
    {
        int min = 0, middle = 0, max = 0;

        //These are the variables that I will use to help find the even and odd values
        int min_counter = 0, middle_counter = 0;

        printf("\nPlease input three numbers:\n");
        printf("1:");
        scanf("%d", &user_input1);

        printf("2:");
        scanf("%d", &user_input2);

        printf("3:");
        scanf("%d", &user_input3);

        //Finding if they are negative values before anything else
        if (user_input1 < 0 || user_input2 < 0 || user_input3 < 0)
        {
            printf("\nPlease start over again and enter postitve numbers\n");
            return 0;
        }

        //These if statements are used to find the max middle and min values
        if (user_input1 > user_input2 && user_input2 > user_input3)
        {
            max = user_input1;
            middle = user_input2;
            min = user_input3;
        }

        if (user_input1 > user_input3 && user_input3 > user_input2)
        {
            max = user_input1;
            middle = user_input3;
            min = user_input3;
        }

        if (user_input2 > user_input1 && user_input1 > user_input3)
        {
            max = user_input2;
            middle = user_input1;
            min = user_input3;
        }

        if (user_input2 > user_input3 && user_input3 > user_input1)
        {
            max = user_input2;
            middle = user_input3;
            min = user_input1;
        }

        if (user_input3 > user_input1 && user_input1 > user_input2)
        {
            max = user_input3;
            middle = user_input1;
            min = user_input2;
        }

        if (user_input3 > user_input2 && user_input2 > user_input1)
        {
            max = user_input3;
            middle = user_input2;
            min = user_input1;
        }

        //Finding if the difference between them is greater than 7
        if (max - middle < 7 || middle - min < 7 || max - min < 7)
        {
            printf("\nPlease choose values that are more than 7 units apart.\n");
            return 0;
        }

        //Printing out the values for max middle and min
        printf("\nMin: %d\n", min);
        printf("Middle: %d\n", middle);
        printf("Max: %d\n", max);

        min_counter = min;
        middle_counter = middle;

        //Checking for odd numbers
        printf("\nThe odd numbers are:\n");
        while (min_counter < middle)
        {
            if (min_counter % 2 == 1)
            {
                printf("Value: %d\n", min_counter);
                min_counter++;
            }
            else
            {
                min_counter++;
            }
        }

        //Checking for even numbers
        printf("\nThe even numbers are:\n");
        while (middle_counter < max)
        {
            if (middle_counter % 2 == 0)
            {
                printf("Value: %d\n", middle_counter);
                middle_counter++;
            }
            else
            {
                middle_counter++;
            }
        }
    }

    return 0;
}
