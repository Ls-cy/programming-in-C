#include <stdio.h>

#define DAYS 5
#define MIN_TEMP -30
#define MAX_TEMP 130

int main() {
    float temps[DAYS];
    int i = 0;

    // Get 5 valid temperatures
    while (i < DAYS) {
        float input;
        printf("Enter temperature for day %d: ", i + 1);
        scanf_s("%f", &input);

        if (input < MIN_TEMP || input > MAX_TEMP) {
            printf("EXCEPTION Temperature %.0f is invalid, Please enter a valid temperature between -30 and 130\n", input);
        }
        else {
            temps[i] = input;
            i++;
        }
    }

    // Determine trend
    int warmer = 1, cooler = 1;
    for (i = 1; i < DAYS; i++) {
        if (temps[i] <= temps[i - 1]) {
            warmer = 0;
        }
        if (temps[i] >= temps[i - 1]) {
            cooler = 0;
        }
    }

    // Output trend
    if (warmer) {
        printf("OUTPUT Getting Warmer\n");
    }
    else if (cooler) {
        printf("OUTPUT Getting Colder\n");
    }
    else {
        printf("OUTPUT It's a mixed bag\n");
    }

    // Display temperatures
    printf("OUTPUT 5-day Temperature [");
    for (i = 0; i < DAYS; i++) {
        printf("%.0f", temps[i]);
        if (i < DAYS - 1) printf(", ");
    }
    printf("]\n");

    // Calculate and display average
    float sum = 0;
    for (i = 0; i < DAYS; i++) {
        sum += temps[i];
    }
    float average = sum / DAYS;
    printf("OUTPUT Average Temperature is %.1f degrees\n", average);

    return 0;
}
