#include <stdio.h>

int main() {
    int number;

    do {
        printf("Enter a positive number: ");
        scanf("%d", &number);
        if (number <= 0) {
            printf("Invalid input. Please enter a positive number.\n");
        }
    } while (number <= 0);

    printf("Final accepted input: %d\n", number);
    return 0;
}
