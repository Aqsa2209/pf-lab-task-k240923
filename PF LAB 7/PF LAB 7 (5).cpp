#include <stdio.h>
int main() {
    int arr[20];
    printf("Enter 20 numbers:\n");
    for (int i = 0; i < 20; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Array in reverse order:\n");
    for (int i = 19; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
