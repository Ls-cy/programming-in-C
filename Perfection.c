#include <stdio.h>

// Function to check if a number is perfect
int isPerfect(int num) {
    int sum = 0;

    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }

    return sum == num;
}

int main() {
    int input;

    // Part 1: Display all perfect numbers from 1 to 10000
    printf("Perfect numbers between 1 and 10000 are:\n");
    for (int i = 1; i <= 10000; i++) {
        if (isPerfect(i)) {
            printf("%d\n", i);
        }
    }

    // Part 2: Accept user input and check if it's perfect
    printf("\nEnter a number to check if it's a Perfect Number:\n");

    if (scanf_s("%d", &input) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }

    if (isPerfect(input)) {
        printf("Perfect Number\n");
    }
    else {
        printf("Not A Perfect Number\n");
    }

    return 0;
}
