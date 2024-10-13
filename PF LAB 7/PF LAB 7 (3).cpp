#include <stdio.h>

int main() {
    int inputArray[12];
    int pairSumArray[6];
    printf("Enter 12 numbers:\n");
    for (int i = 0; i < 12; i++) {
        scanf("%d", &inputArray[i]);
    }
    for (int i = 0; i < 6; i++) {
        pairSumArray[i] = inputArray[2 * i] + inputArray[2 * i + 1];
    }
    printf("Input array: {");
    for (int i = 0; i < 12; i++) {
        printf("%d", inputArray[i]);
        if (i < 11) {
            printf(", ");
        }
    }
    printf("}\n");
    printf("Pair Sum array: {");
    for (int i = 0; i < 6; i++) {
        printf("%d", pairSumArray[i]);
        if (i < 5) {
            printf(", ");
        }
    }
    printf("}\n");
    return 0;
}
