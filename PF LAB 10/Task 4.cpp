#include <stdio.h>
#include <string.h>
struct TravelPackage {
    char name[50];
    char destination[50];
    int duration;
    float cost;
    int seats;
};
void displayPackages(struct TravelPackage packages[], int count);
void bookPackage(struct TravelPackage packages[], int count);

int main() {
    struct TravelPackage packages[] = {
        {"Beach Paradise", "Hawaii", 7, 1200.50, 10},
        {"Mountain Adventure", "Swiss Alps", 10, 1500.75, 5},
        {"City Escape", "New York", 5, 800.00, 15}
    };
    int count = 3;
    int choice;
    while (1) {
        printf("\n--- Travel Booking System ---\n");
        printf("1. View Packages\n");
        printf("2. Book Package\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            displayPackages(packages, count);
        else if (choice == 2)
            bookPackage(packages, count);
        else if (choice == 3)
            break;
        else
            printf("Invalid choice! Try again.\n");
    }

    printf("Goodbye!\n");
    return 0;
}

void displayPackages(struct TravelPackage packages[], int count) {
    printf("\nAvailable Packages:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s to %s, %d days, $%.2f, Seats: %d\n",
               i + 1, packages[i].name, packages[i].destination,
               packages[i].duration, packages[i].cost, packages[i].seats);
    }
}

void bookPackage(struct TravelPackage packages[], int count) {
    int choice;
    printf("\nEnter package number to book: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > count) {
        printf("Invalid package number!\n");
        return;
    }

    if (packages[choice - 1].seats > 0) {
        packages[choice - 1].seats--;
        printf("Booking successful for %s!\n", packages[choice - 1].name);
    } else {
        printf("Sorry, no seats available for %s.\n", packages[choice - 1].name);
    }
}

