#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "books.txt"

struct Book {
    int bookID;
    char title[50];
    char author[50];
    int quantity;
    float price;
};

void addBook();
void viewBooks();
void searchBook();
void calculateInventoryValue();
int loadBooks(struct Book* books, int maxBooks);
void saveBooks(struct Book* books, int count);

int main() {
    int choice;
    do {
        printf("\nLibrary Management System\n");
        printf("1. Add New Book\n");
        printf("2. View All Books\n");
        printf("3. Search for a Book\n");
        printf("4. Calculate Inventory Value\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: viewBooks(); break;
            case 3: searchBook(); break;
            case 4: calculateInventoryValue(); break;
            case 5: printf("Exiting. Goodbye!\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addBook() {
    struct Book books[100];
    int count = loadBooks(books, 100);

    struct Book newBook;
    printf("Enter Book ID: ");
    scanf("%d", &newBook.bookID);
    for (int i = 0; i < count; i++) {
        if (books[i].bookID == newBook.bookID) {
            printf("Book ID already exists!\n");
            return;
        }
    }
    printf("Enter Title: ");
    scanf(" %[^\n]", newBook.title);
    printf("Enter Author: ");
    scanf(" %[^\n]", newBook.author);
    printf("Enter Quantity: ");
    scanf("%d", &newBook.quantity);
    printf("Enter Price: ");
    scanf("%f", &newBook.price);

    books[count++] = newBook;
    saveBooks(books, count);
    printf("Book added successfully!\n");
}

void viewBooks() {
    struct Book books[100];
    int count = loadBooks(books, 100);
    if (count == 0) {
        printf("No books found.\n");
        return;
    }

    printf("\nBook Records:\n");
    printf("ID\tTitle\t\tAuthor\t\tQuantity\tPrice\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%s\t\t%d\t\t%.2f\n", books[i].bookID, books[i].title, books[i].author, books[i].quantity, books[i].price);
    }
}

void searchBook() {
    struct Book books[100];
    int count = loadBooks(books, 100);

    int searchID;
    printf("Enter Book ID to search: ");
    scanf("%d", &searchID);

    for (int i = 0; i < count; i++) {
        if (books[i].bookID == searchID) {
            printf("Book Found: ID: %d, Title: %s, Author: %s, Quantity: %d, Price: %.2f\n",
                   books[i].bookID, books[i].title, books[i].author, books[i].quantity, books[i].price);
            return;
        }
    }
    printf("Book not found.\n");
}

void calculateInventoryValue() {
    struct Book books[100];
    int count = loadBooks(books, 100);
    float totalValue = 0;

    for (int i = 0; i < count; i++) {
        totalValue += books[i].quantity * books[i].price;
    }

    printf("Total Inventory Value: %.2f\n", totalValue);
}

int loadBooks(struct Book* books, int maxBooks) {
    FILE* file = fopen(FILE_NAME, "r");
    if (!file) return 0;

    int count = 0;
    while (fscanf(file, "%d %[^\n] %[^\n] %d %f\n", &books[count].bookID, books[count].title, books[count].author, &books[count].quantity, &books[count].price) == 5) {
        count++;
        if (count >= maxBooks) break;
    }

    fclose(file);
    return count;
}

void saveBooks(struct Book* books, int count) {
    FILE* file = fopen(FILE_NAME, "w");
    if (!file) {
        printf("Error: Could not open file for writing.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d\n%s\n%s\n%d\n%.2f\n", books[i].bookID, books[i].title, books[i].author, books[i].quantity, books[i].price);
    }

    fclose(file);
}

