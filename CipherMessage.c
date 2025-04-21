#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 1000

// Encrypt a single character using Caesar Cipher
char encryptChar(char ch, int key) {
    if (isalpha(ch)) {
        char base = isupper(ch) ? 'A' : 'a';
        return (char)(((ch - base + key) % 26) + base);
    }
    return ch; 
}

int main() {
    char message[MAX_LEN];
    int key;

    
    printf("Enter a message to encrypt (letters only will be encrypted):\n");
    fgets(message, MAX_LEN, stdin);

    
    printf("Enter the encryption key (1 to 25): ");
    scanf_s("%d", &key);
    key = key % 26;  

    printf("\nEncrypted Message:\n");
    for (int i = 0; message[i] != '\0'; i++) {
        printf("%c", encryptChar(message[i], key));
    }

    printf("\n");
    return 0;
}
