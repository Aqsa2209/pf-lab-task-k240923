#include <stdio.h>
#include <string.h>

struct Car {
    char make[50];
    char model[50];
    int year;
    float price;
    float mileage;
};

void addCar(struct Car cars[], int *count) {
    printf("Enter make: ");
    scanf("%s", cars[*count].make);
    printf("Enter model: ");
    scanf("%s", cars[*count].model);
    printf("Enter year: ");
    scanf("%d", &cars[*count].year);
    printf("Enter price: ");
    scanf("%f", &cars[*count].price);
    printf("Enter mileage: ");
    scanf("%f", &cars[*count].mileage);
    (*count)++;
}

void displayCars(struct Car cars[], int count) {
    printf("\nAvailable Cars:\n");
    for (int i = 0; i < count; i++) {
        printf("%s %s (%d) - $%.2f, Mileage: %.2f\n", cars[i].make, cars[i].model, cars[i].year, cars[i].price, cars[i].mileage);
    }
}

void searchCar(struct Car cars[], int count) {
    char query[50];
    printf("Enter make or model to search: ");
    scanf("%s", query);
    printf("\nSearch Results:\n");
    for (int i = 0; i < count; i++) {
        if (strcmp(cars[i].make, query) == 0 || strcmp(cars[i].model, query) == 0) {
            printf("%s %s (%d) - $%.2f, Mileage: %.2f\n", cars[i].make, cars[i].model, cars[i].year, cars[i].price, cars[i].mileage);
        }
    }
}

int main() {
    struct Car cars[100];
    int count = 0;
    int choice;

    do {
        printf("\n1. Add Car\n2. Display Cars\n3. Search Car\n4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addCar(cars, &count); break;
            case 2: displayCars(cars, count); break;
            case 3: searchCar(cars, count); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid option. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
