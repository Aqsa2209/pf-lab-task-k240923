#include <stdio.h>

int main() {
    int value, sum = 0;

    printf("Enter a value (0 to stop): ");
    scanf("%d", &value);

    while (value != 0) {
        sum += value; 
        printf("Current sum: %d\n", sum);
        printf("Enter a value (0 to stop): ");
        scanf("%d", &value);
    }

    printf("Final sum: %d\n", sum);
    return 0;
}
