#include <stdio.h>

// Function to check if a number is perfect
int isPerfect(int num) {
    int sum = 0;

    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }

    return sum == num;
}

// Function to print the result
void checkNumber(int num) {
    if (isPerfect(num)) {
        printf("%d is a Perfect Number\n", num);
    }
    else {
        printf("%d is Not A Perfect Number\n", num);
    }
}

// Main function
int main() {
    int num;

    printf("Enter a number to check: ");
    scanf_s("%d", &num);  

    checkNumber(num);

    return 0;
}
