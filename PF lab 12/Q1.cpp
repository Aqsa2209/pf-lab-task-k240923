#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_students, i, j;
    printf("Enter the number of students: ");
    scanf("%d", &num_students);
    float **grades = (float **)malloc(num_students * sizeof(float *));
    if (grades == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    int *num_grades = (int *)malloc(num_students * sizeof(int));
    if (num_grades == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(grades);
        return 1;
    }
    for (i = 0; i < num_students; i++) {
        printf("Enter the number of grades for student %d: ", i + 1);
        scanf("%d", &num_grades[i]);
        grades[i] = (float *)malloc(num_grades[i] * sizeof(float));
        if (grades[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            for (int k = 0; k < i; k++) {
                free(grades[k]);
            }
            free(grades);
            free(num_grades);
            return 1;
        }
        printf("Enter grades for student %d:\n", i + 1);
        for (j = 0; j < num_grades[i]; j++) {
            printf("Grade %d: ", j + 1);
            scanf("%f", &grades[i][j]);
        }
    }
    printf("\nEntered Grades:\n");
    for (i = 0; i < num_students; i++) {
        printf("Student %d Grades: ", i + 1);
        for (j = 0; j < num_grades[i]; j++) {
            printf("%.0f ", grades[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < num_students; i++) {
        free(grades[i]);
    }
    free(grades);
    free(num_grades);

    return 0;
}
