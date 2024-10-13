#include <stdio.h>
int main() {
    int array[] = {1, 1, 1, 1, 1, 1, 5, 1, 1, 1, 1, 1}; 
    int size = sizeof(array) / sizeof(array[0]);  
    int searchNum, found = 0;

    printf("Array: {");
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("}\n");
    printf("Enter integer to search: ");
    scanf("%d", &searchNum);
    for (int i = 0; i < size; i++) {
        if (array[i] == searchNum) {
            printf("%d found at index %d\n", searchNum, i);
            found = 1;
            break; 
        }
    }
    if (!found) {
        printf("Number not found\n");
    }
    return 0;
}
