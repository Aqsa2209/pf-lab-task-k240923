#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;  
    int size;    
    char operation; 
    int pos;    
    int value;  
} TestCase;
void insert(int **array, int *size, int pos, int value) {
    if (pos < 0 || pos > *size) {
        printf("Invalid position for insertion\n");
        return;
    }
    *array = (int *)realloc(*array, (*size + 1) * sizeof(int));
    for (int i = *size; i > pos; i--) {
        (*array)[i] = (*array)[i - 1];
    }
    (*array)[pos] = value;
    (*size)++;
}
void deleteElement(int **array, int *size, int pos) {
    if (pos < 0 || pos >= *size) {
        printf("Invalid position for deletion\n");
        return;
    }
    for (int i = pos; i < *size - 1; i++) {
        (*array)[i] = (*array)[i + 1];
    }
    (*size)--;
    *array = (int *)realloc(*array, *size * sizeof(int));
}
void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int T; 
    scanf("%d", &T);
    TestCase *testCases = (TestCase *)malloc(T * sizeof(TestCase));
    for (int t = 0; t < T; t++) {
        scanf("%d", &testCases[t].size);
        testCases[t].array = (int *)malloc(testCases[t].size * sizeof(int));
        for (int i = 0; i < testCases[t].size; i++) {
            scanf("%d", &testCases[t].array[i]);
        }
        scanf(" %c", &testCases[t].operation);

        if (testCases[t].operation == 'I') {
            scanf("%d %d", &testCases[t].pos, &testCases[t].value);
        } else if (testCases[t].operation == 'D') {
            scanf("%d", &testCases[t].pos);
        }
    }

    for (int t = 0; t < T; t++) {
        if (testCases[t].operation == 'I') {
            insert(&testCases[t].array, &testCases[t].size, testCases[t].pos, testCases[t].value);
        } else if (testCases[t].operation == 'D') {
            deleteElement(&testCases[t].array, &testCases[t].size, testCases[t].pos);
        }
        printArray(testCases[t].array, testCases[t].size);
        free(testCases[t].array);
    }

    free(testCases);
    return 0;
}

