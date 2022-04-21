#include <stdio.h>
#include <time.h>

int diceRollEven() {
    int evenDice;
    evenDice = (rand() % (4 + 1 - 2)) + 2;

    if (evenDice == 3) {
        diceRollEven();
    } else {
        return evenDice;
    }
}

int diceRollOdd() {
    int oddDice;
    oddDice = (rand() % (5 + 1 - 1)) + 1;

    if (oddDice == 2 || oddDice == 4) {
        diceRollOdd();
    } else {
        return oddDice;
    }
}

int main() {
    srand(time(NULL));
    float rollCount;
    printf("Please enter a number of rolls\n");
    scanf("%f", &rollCount);

    while (rollCount < 10 || rollCount > 1000000){
        printf("Please enter a number of rolls\n");
        scanf("%f", &rollCount);
    }

    int sum, count;
    int three = 0, five = 0, seven = 0, nine = 0;

    for (count = 1; count <= rollCount; count++) {
        sum = diceRollEven() + diceRollOdd();
        switch (sum) {
            case 3:
                three++;
                break;
            case 5:
                five++;
                break;
            case 7:
                seven++;
                break;
            case 9:
                nine++;
                break;
            default:
                return 1;
        }

    }
    int numerator = (3 * three + 5 * five + 7 * seven + 9 * nine);
    float mean = numerator/rollCount;

    printf("Sum     Frequency\n");
    printf(" 3          %d\n 5          %d\n 7          %d\n 9          %d\n", three, five, seven, nine);
    printf("Mean value is %1.2f", mean);
    return 0;

}