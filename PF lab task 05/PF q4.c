#include <stdio.h>

int main() {
    float purchaseAmount;
    char membership[4]; // "yes" or "no"

    printf("Enter the total purchase amount: ");
    scanf("%f", &purchaseAmount);
    printf("Do you have a membership? (yes/no): ");
    scanf("%s", membership);

    float discount = (purchaseAmount > 100 && strcmp(membership, "yes") == 0) ? 0.1 * purchaseAmount : 0;

    printf("Discount amount: $%.2f\n", discount);

    return 0;
}