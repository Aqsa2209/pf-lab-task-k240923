#include <stdio.h>
int main() {
    int n, i, j;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < i; j++) {
            printf(" ");
        }
        for (j = n - i; j >= 1; j--) {
            printf("%d ", j);
        }
        printf("\n");
    }
    for (i = 1; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            printf(" ");
        }
        for (j = i + 1; j >= 1; j--) {
            printf("%d ", j);
        }
        printf("\n");
    }
    return 0;
}

