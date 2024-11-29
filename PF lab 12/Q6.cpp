#include <stdio.h>
#include <stdlib.h>

int main() {
    int n; 
    int *arr; 
    printf("Enter the total number of elements (1 to 100): ");
    scanf("%d", &n);
    if (n < 1 || n > 100) {
        printf("Invalid number of elements. Please enter a number between 1 and 100.\n");
        return 1; 
    }

    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1; 
    }

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    int largest = arr[0]; 
    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i]; 
        }
    }
    printf("The largest element is: %d\n", largest);
    free(arr); 
    return 0; 
}
