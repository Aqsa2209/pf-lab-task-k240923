#include <stdio.h>

int main() {
    const int price_bolt = 5;
    const int price_nut = 3;
    const int price_washer = 1;
    int num_bolts, num_nuts, num_washers;
    printf("Enter the number of bolts: ");
    scanf("%d", &num_bolts);
    printf("Enter the number of nuts: ");
    scanf("%d", &num_nuts);
    printf("Enter the number of washers: ");
    scanf("%d", &num_washers);

    int total_cost = (num_bolts * price_bolt) + (num_nuts * price_nut) + (num_washers * price_washer);

    int error_nuts = (num_nuts < num_bolts);
    int error_washers = (num_washers < 2 * num_bolts);

    if (error_nuts || error_washers) {
        if (error_nuts) {
            printf("Check the Order: too few nuts\n");
        }
        if (error_washers) {
            printf("Check the Order: too few washers\n");
        }
    } else {
        printf("Order is OK.\n");
    }

    printf("Total cost: %d cents\n", total_cost);

    return 0;
}
