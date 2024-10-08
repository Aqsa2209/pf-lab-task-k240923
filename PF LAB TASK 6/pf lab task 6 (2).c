#include <stdio.h>

int main() {
    int number;
    printf("Enter a positive integer (greater than or equal to 1): ");
    scanf("%d", &number);

    if (number < 1) {
        printf("Please enter a number greater than or equal to 1.\n");
        return 1;
    }

    int i = 1; // Start from 1
    printf("Even numbers from 1 to %d are: ", number);
    while (i <= number) {
        if (i % 2 == 0) {
            printf("%d ", i);
        }
        i++;
    }
    printf("\n");
    return 0;
}
