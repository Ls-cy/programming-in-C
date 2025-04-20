#include <stdio.h>

// Function to determine hurricane category
int getCategory(float windSpeed) {
    if (windSpeed >= 157)
        return 5;
    else if (windSpeed >= 130)
        return 4;
    else if (windSpeed >= 111)
        return 3;
    else if (windSpeed >= 96)
        return 2;
    else if (windSpeed >= 74)
        return 1;
    else
        return 0; // Not a hurricane
}

// Function to print category description
void displayCategory(int category) {
    if (category == 0)
        printf("Not a Hurricane\n");
    else
        printf("Category %d Hurricane\n", category);
}

int main() {
    float windSpeed;

    printf("Enter wind speed in mph: ");
    scanf_s("%f", &windSpeed);

    int category = getCategory(windSpeed);
    displayCategory(category);

    return 0;
}
