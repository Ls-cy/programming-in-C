#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define NUM_SALESPERSONS 3

int findSalespersonIndex(char inputInitial, char initials[], int size) {
    for (int i = 0; i < size; i++) {
        if (toupper(inputInitial) == initials[i]) {
            return i;
        }
    }
    return -1;
}

int main() {
    char initials[NUM_SALESPERSONS] = { 'D', 'E', 'F' };
    char* names[NUM_SALESPERSONS] = { "Danielle", "Edward", "Francis" };
    float sales[NUM_SALESPERSONS] = { 0.0, 0.0, 0.0 };
    char inputInitial;
    float saleAmount;

    while (1) {
        printf("Enter salesperson initial (D, E, F) or Z to quit: ");
        scanf_s(" %c", &inputInitial, 1);

        if (toupper(inputInitial) == 'Z') {
            break;
        }

        int index = findSalespersonIndex(inputInitial, initials, NUM_SALESPERSONS);

        if (index == -1) {
            printf("Error, invalid salesperson selected, please try again.\n");
            while (getchar() != '\n');
            continue;
        }

        printf("Enter sale amount: ");
        if (scanf_s("%f", &saleAmount) != 1 || saleAmount < 0) {
            printf("Invalid sale amount. Please try again.\n");
            while (getchar() != '\n'); 
            continue;
        }

        sales[index] += saleAmount;
    }

    // Print sales summary
    float grandTotal = 0;
    printf("\n--- Sales Summary ---\n");
    for (int i = 0; i < NUM_SALESPERSONS; i++) {
        printf("%s's Total: $%.2f\n", names[i], sales[i]);
        grandTotal += sales[i];
    }
    printf("Grand Total: $%.2f\n", grandTotal);

    // Determine highest sale
    int topIndex = 0;
    for (int i = 1; i < NUM_SALESPERSONS; i++) {
        if (sales[i] > sales[topIndex]) {
            topIndex = i;
        }
    }
    printf("Highest Sale: %c\n", initials[topIndex]);

    return 0;
}
