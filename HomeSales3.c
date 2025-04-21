#include <stdio.h>
#include <ctype.h>

#define NUM_SALESPERSONS 3

struct SalesPerson {
    char name[20];
    char initial;
    float totalSales;
};

int findSalespersonIndex(char inputInitial, struct SalesPerson people[], int size) {
    inputInitial = toupper(inputInitial);
    for (int i = 0; i < size; i++) {
        if (inputInitial == people[i].initial) {
            return i;
        }
    }
    return -1;
}

int main() {
    struct SalesPerson salesPeople[NUM_SALESPERSONS] = {
        {"Danielle", 'D', 0.0},
        {"Edward",   'E', 0.0},
        {"Francis",  'F', 0.0}
    };

    char inputInitial;
    float saleAmount;

    printf("Enter salesperson initial (D, E, F) or Z to quit:\n");

    while (1) {
        printf("Salesperson: ");
        if (scanf_s(" %c", &inputInitial, 1) != 1) {  
            printf("Invalid input. Please try again.\n");
            while (getchar() != '\n');
            continue;
        }

        inputInitial = toupper(inputInitial);

        if (inputInitial == 'Z') {
            break;
        }

        int index = findSalespersonIndex(inputInitial, salesPeople, NUM_SALESPERSONS);
        if (index == -1) {
            printf("Error, invalid salesperson selected, please try again.\n");
            while (getchar() != '\n');
            continue;
        }

        printf("Sale amount: ");
        if (scanf_s("%f", &saleAmount) != 1 || saleAmount < 0) {
            printf("Invalid sale amount. Please try again.\n");
            while (getchar() != '\n');
            continue;
        }

        salesPeople[index].totalSales += saleAmount;
    }

    float grandTotal = 0.0;
    int topIndex = 0;

    printf("\n--- Sales Summary ---\n");
    for (int i = 0; i < NUM_SALESPERSONS; i++) {
        printf("%s's Total: $%.2f\n", salesPeople[i].name, salesPeople[i].totalSales);
        grandTotal += salesPeople[i].totalSales;

        if (salesPeople[i].totalSales > salesPeople[topIndex].totalSales) {
            topIndex = i;
        }
    }

    printf("Grand Total: $%.2f\n", grandTotal);
    printf("Highest Sale: %c\n", salesPeople[topIndex].initial);

    return 0;
}
