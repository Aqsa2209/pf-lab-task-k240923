#include <stdio.h>
#include <string.h>
struct Invoice {
    char partNumber[50];
    char partDescription[100];
    int quantity;
    float pricePerItem;
    float invoiceAmount;
};
void initializeInvoice(struct Invoice *inv) {
    printf("Enter Part Number: ");
    scanf(" %[^\n]s", inv->partNumber);
    printf("Enter Part Description: ");
    scanf(" %[^\n]s", inv->partDescription);
    printf("Enter Quantity: ");
    scanf("%d", &inv->quantity);
    if (inv->quantity < 0) {
        printf("Invalid quantity! Setting quantity to 0.\n");
        inv->quantity = 0;
    }
    printf("Enter Price per Item: ");
    scanf("%f", &inv->pricePerItem);
    if (inv->pricePerItem < 0) {
        printf("Invalid price! Setting price to 0.00.\n");
        inv->pricePerItem = 0.0;
    }
    inv->invoiceAmount = inv->quantity * inv->pricePerItem;
}
void displayInvoice(const struct Invoice *inv) {
    printf("Invoice Details:\n");
    printf("Part Number: %s\n", inv->partNumber);
    printf("Part Description: %s\n", inv->partDescription);
    printf("Quantity: %d\n", inv->quantity);
    printf("Price per Item: %.2f\n", inv->pricePerItem);
    printf("Invoice Amount: %.2f\n", inv->invoiceAmount);
}

int main() {
    struct Invoice inv1, inv2;

    printf("Enter details for Invoice 1:\n");
    initializeInvoice(&inv1);

    printf("\nEnter details for Invoice 2:\n");
    initializeInvoice(&inv2);

    printf("\nDisplaying Invoices:\n");
    printf("\nInvoice 1:\n");
    displayInvoice(&inv1);

    printf("\nInvoice 2:\n");
    displayInvoice(&inv2);

    return 0;
}

