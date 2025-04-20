#include <stdio.h>

int main() {
    float windSpeed;

    // Prompt the user
    printf("Enter the sustained wind speed in mph:\n");

    // Check scanf return value
    if (scanf_s("%f", &windSpeed) != 1) {
        printf("Invalid input. Please enter a number.\n");
        return 1; // exit with error
    }

    // Determine the hurricane category
    if (windSpeed >= 157) {
        printf("Category Five Hurricane\n");
    }
    else if (windSpeed >= 130) {
        printf("Category Four Hurricane\n");
    }
    else if (windSpeed >= 111) {
        printf("Category Three Hurricane\n");
    }
    else if (windSpeed >= 96) {
        printf("Category Two Hurricane\n");
    }
    else if (windSpeed >= 74) {
        printf("Category One Hurricane\n");
    }
    else {
        printf("Not a Hurricane\n");
    }

    return 0;
}
