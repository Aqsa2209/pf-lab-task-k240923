#include <stdio.h>
#include <string.h>

void reverseString(char *str) {
    if (*str == '\0') {
        return;
    }
    reverseString(str + 1);
    putchar(*str);
}

int main() {
    char sentence[100];
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = '\0'; 
    reverseString(sentence);
    printf("\n");
    return 0;
}
