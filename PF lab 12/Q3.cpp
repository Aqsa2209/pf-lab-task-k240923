#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 4

typedef struct {
    float *data;   
    int size;         
    int capacity;     
} DynamicArray;
void initArray(DynamicArray *arr) {
    arr->data = (float *)malloc(INITIAL_CAPACITY * sizeof(float));
    arr->size = 0;
    arr->capacity = INITIAL_CAPACITY;
}
void addNumber(DynamicArray *arr, float number) {
    if (arr->size >= arr->capacity) {
        arr->capacity *= 2;
        arr->data = (float *)realloc(arr->data, arr->capacity * sizeof(float));
    }
    arr->data[arr->size++] = number;  
}
void displayNumbers(const DynamicArray *arr) {
    if (arr->size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Numbers: ");
    for (int i = 0; i < arr->size; i++) {
        printf("%.2f ", arr->data[i]);
    }
    printf("\n");
}
void removeLast(DynamicArray *arr) {
    if (arr->size > 0) {
        arr->size--;
        if (arr->size < arr->capacity / 4) {
            arr->capacity /= 2;
            arr->data = (float *)realloc(arr->data, arr->capacity * sizeof(float));
        }
    } else {
        printf("Array is already empty.\n");
    }
}
void freeArray(DynamicArray *arr) {
    free(arr->data);
    arr->data = NULL;
}

int main() {
    DynamicArray arr;
    initArray(&arr);
    int choice;
    float number;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add a number\n");
        printf("2. Display numbers\n");
        printf("3. Remove last number\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a floating-point number: ");
                scanf("%f", &number);
                addNumber(&arr, number);
                break;
            case 2:
                displayNumbers(&arr);
                break;
            case 3:
                removeLast(&arr);
                break;
            case 4:
                freeArray(&arr);
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
