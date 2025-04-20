#include <stdio.h>
#include <ctype.h>  // For toupper()

int main() {
    char initial;
    float sale;
    float totalD = 0, totalE = 0, totalF = 0;

    while (1) {
        printf("Enter salesperson initial (D, E, F) or Z to quit: ");
        scanf_s(" %c", &initial, 1);  // Leading space handles leftover newlines, buffer size is 1 for a single char
        initial = toupper(initial);  // Convert input to uppercase

        if (initial == 'Z') {
            break;  // Exit loop when user enters Z or z
        }

        // Check for valid initials
        if (initial == 'D' || initial == 'E' || initial == 'F') {
            printf("Enter sale amount: ");
            if (scanf_s("%f", &sale) != 1 || sale < 0) {
                printf("Invalid sale amount. Please try again.\n");
                while (getchar() != '\n');  // Clear input buffer
                continue;
            }

            // Add sale to the correct salesperson
            if (initial == 'D') {
                totalD += sale;
            }
            else if (initial == 'E') {
                totalE += sale;
            }
            else if (initial == 'F') {
                totalF += sale;
            }
        }
        else {
            printf("Error, invalid salesperson selected, please try again.\n");
            while (getchar() != '\n');  // Clear input buffer in case of invalid input
        }
    }

    // Calculate grand total
    float grandTotal = totalD + totalE + totalF;

    // Display results
    printf("\n--- Sales Summary ---\n");
    printf("Danielle's Total: $%.2f\n", totalD);
    printf("Edward's Total:   $%.2f\n", totalE);
    printf("Francis's Total:  $%.2f\n", totalF);
    printf("Grand Total:      $%.2f\n", grandTotal);

    // Determine which salesperson had the highest total
    char topSalesperson = 'D';
    float topTotal = totalD;

    if (totalE > topTotal) {
        topSalesperson = 'E';
        topTotal = totalE;
    }
    if (totalF > topTotal) {
        topSalesperson = 'F';
        topTotal = totalF;
    }

    printf("Highest Sale:     %c\n", topSalesperson);

    return 0;
}
