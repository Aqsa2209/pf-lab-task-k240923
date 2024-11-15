#include <stdio.h>
void bubbleSortPass(int arr[], int n) {
    if (n == 1)
        return;
    if (arr[n - 2] > arr[n - 1]) {
        int temp = arr[n - 2];
        arr[n - 2] = arr[n - 1];
        arr[n - 1] = temp;
    }
    bubbleSortPass(arr, n - 1);
}
void bubbleSort(int arr[], int n) {
    if (n == 1)
        return;
    bubbleSortPass(arr, n);
    bubbleSort(arr, n - 1);
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
    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    bubbleSort(arr, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}

