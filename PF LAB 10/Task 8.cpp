#include <stdio.h>
void printArrayRecursive(int arr[], int n) {
    if (n == 0)
        return;
    printf("%d ", arr[0]);
    printArrayRecursive(arr + 1, n - 1);
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Array elements: ");
    printArrayRecursive(arr, n);
    printf("\n");
    return 0;
}

