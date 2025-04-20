#define _CRT_SECURE_NO_WARNINGS  // Optional if using strcpy/strtok, but not needed here
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

int isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

// Translate a single word to Pig Latin
void translateWordToPigLatin(char* word) {
    char original[100];
    strcpy_s(original, sizeof(original), word);

    // Save punctuation (if any)
    int len = (int)strlen(word);
    char punctuation = '\0';
    if (ispunct(word[len - 1])) {
        punctuation = word[len - 1];
        word[len - 1] = '\0';
    }

    // Handle apostrophes like "all's"
    char* apostrophe = strchr(word, '\'');
    if (apostrophe != NULL) {
        int index = (int)(apostrophe - word);
        char first[50], second[50];
        strncpy_s(first, sizeof(first), word, index);
        first[index] = '\0';
        strcpy_s(second, sizeof(second), apostrophe + 1);

        // Translate both parts separately
        translateWordToPigLatin(first);
        printf("'");
        translateWordToPigLatin(second);
        if (punctuation) printf("%c", punctuation);
        return;
    }

    // Actual Pig Latin logic
    if (isVowel(word[0])) {
        printf("%syay", word);
    }
    else {
        int i = 0;
        while (word[i] && !isVowel(word[i])) {
            i++;
        }
        if (i == 0) i = 1; // at least one consonant
        printf("%s", &word[i]);
        for (int j = 0; j < i; j++) {
            printf("%c", word[j]);
        }
        printf("ay");
    }

    if (punctuation) {
        printf("%c", punctuation);
    }
}

// Main function to process a sentence
int main() {
    char input[MAX];
    char* context = NULL;

    printf("Enter an English sentence:\n");
    fgets(input, MAX, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline

    printf("\nPig Latin Translation:\n");

    char* token = strtok_s(input, " ", &context);
    while (token != NULL) {
        translateWordToPigLatin(token);
        printf(" ");
        token = strtok_s(NULL, " ", &context);
    }

    printf("\n");
    return 0;
}
