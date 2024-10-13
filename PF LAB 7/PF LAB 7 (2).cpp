#include <stdio.h>

int main() {
    int array[10];
    printf("Enter 10 numbers:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &array[i]);
    }
    printf("Before: {");
    for (int i = 0; i < 10; i++) {
        printf("%d", array[i]);
        if (i < 9) {
            printf(", ");
        }
    }
    printf("}\n");
    for (int i = 0; i < 9; i++) {
        array[i] = array[i + 1];
    }
    array[9] = 0; 
    printf("After : {");
    for (int i = 0; i < 10; i++) {
        printf("%d", array[i]);
        if (i < 9) {
            printf(", ");
        }
    }
    printf("}\n");
    return 0;
}
