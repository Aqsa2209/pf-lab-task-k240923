#include <stdio.h>
int main() {
    int arr[15], sum = 0;
    printf("Enter 15 numbers:\n");
    for (int i = 0; i < 15; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < 15; i++) {
        sum += arr[i];
    }

    printf("Sum of elements = %d\n", sum);
    return 0;
}
