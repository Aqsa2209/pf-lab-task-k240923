#include <stdio.h>
#include <stdlib.h>

void makeEven(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0) { // Check if the number is odd
            arr[i]--; // Decrease odd numbers by 1
        }
    }
}

int main() {
    int size;

    // Ask the user for the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Input the array elements
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Make all numbers even
    makeEven(arr, size);

    // Display the modified array
    printf("Modified array (only even numbers):\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(arr);

    return 0;
}
