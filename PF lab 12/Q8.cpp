#include <stdio.h>
#include <stdlib.h>

int main() {
    int numberOfPoints;
    double totalProfit = 0.0;
    printf("Enter the total number of points in the facility: ");
    scanf("%d", &numberOfPoints);
    if (numberOfPoints <= 0) {
        printf("Invalid number of points. Please enter a positive integer.\n");
        return 1; 
    }
    double *fees = (double *)malloc(numberOfPoints * sizeof(double));
    if (fees == NULL) {
        printf("Memory allocation failed!\n");
        return 1; 
    }
    for (int i = 0; i < numberOfPoints; i++) {
        printf("Enter fee for point %d: ", i + 1);
        scanf("%lf", &fees[i]);
        if (fees[i] < 0) {
            printf("Negative fee entered for point %d. Setting fee to 0.\n", i + 1);
            fees[i] = 0; 
        }

        totalProfit += fees[i]; 
    }
    printf("Total Profit for the facility: $%.2f\n", totalProfit);
    free(fees);

    return 0; 
}
