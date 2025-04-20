#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 140

int main() {
    char message[1000];

    printf("Enter your message:\n");
    fgets(message, sizeof(message), stdin);

    // Remove trailing newline character if it exists
    size_t len = strlen(message);
    if (len > 0 && message[len - 1] == '\n') {
        message[len - 1] = '\0';
        len--;
    }

    if (len <= MAX_LENGTH) {
        printf("Posted\n");
    }
    else {
        printf("Rejected\n");
    }

    return 0;
}
