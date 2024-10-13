#include <stdio.h>
int main() {
    int arr[30], min, max;
    printf("Enter 30 numbers:\n");
    for (int i = 0; i < 30; i++) {
        scanf("%d", &arr[i]);
    }
    min = max = arr[0];
    for (int i = 1; i < 30; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Minimum Number = %d\n", min);
    printf("Maximum Number = %d\n", max);
    return 0;
}
