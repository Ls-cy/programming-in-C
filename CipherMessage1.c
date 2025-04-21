#define _CRT_SECURE_NO_WARNINGS  

#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Caesar Cipher Encryption Function
void caesarCipher(char* text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        // Encrypt uppercase letters
        if (isupper(ch)) {
            text[i] = ((ch - 'A' + shift) % 26 + 26) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (islower(ch)) {
            text[i] = ((ch - 'a' + shift) % 26 + 26) % 26 + 'a';
        }
        
    }
}

int main() {
    char text[1000];
    int shift;

    printf("Enter Text: ");
    fgets(text, sizeof(text), stdin);

   
    text[strcspn(text, "\n")] = '\0';

    printf("Enter Shift: ");
    scanf_s("%d", &shift); 

    // Save original text before encryption
    char originalText[1000];
    strcpy_s(originalText, sizeof(originalText), text);  

    caesarCipher(text, shift);

    printf("\nText: %s\n", originalText);
    printf("Shift: %d\n", shift);
    printf("Cipher: %s\n", text);

    return 0;
}
