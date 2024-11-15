#include <stdio.h>
#include <string.h>
#define MAX_BOOKS 100
typedef struct Book {
    char title[100];
    char author[100];
    char isbn[20];
    int publication_year;
    int is_available; 
} Book;
typedef struct Library {
    Book books[MAX_BOOKS];
    int count;
} Library;

void add_book(Library* library) {
    if (library->count < MAX_BOOKS) {
        Book new_book;
        printf("Enter book title: ");
        getchar(); // Clear newline from buffer
        fgets(new_book.title, sizeof(new_book.title), stdin);
        new_book.title[strcspn(new_book.title, "\n")] = 0; 

        printf("Enter author: ");
        fgets(new_book.author, sizeof(new_book.author), stdin);
        new_book.author[strcspn(new_book.author, "\n")] = 0; 

        printf("Enter ISBN: ");
        fgets(new_book.isbn, sizeof(new_book.isbn), stdin);
        new_book.isbn[strcspn(new_book.isbn, "\n")] = 0;

        printf("Enter publication year: ");
        scanf("%d", &new_book.publication_year);

        new_book.is_available = 1; 
        library->books[library->count++] = new_book;
        printf("Book added successfully!\n");
    } else {
        printf("Library is full!\n");
    }
}
void search_books(Library* library) {
    char query[100];
    printf("Enter title or author to search: ");
    getchar(); 
    fgets(query, sizeof(query), stdin);
    query[strcspn(query, "\n")] = 0;

    for (int i = 0; i < library->count; i++) {
        if (strstr(library->books[i].title, query) || strstr(library->books[i].author, query)) {
            printf("Found: %s by %s (ISBN: %s, Year: %d, Available: %s)\n",
                   library->books[i].title,
                   library->books[i].author,
                   library->books[i].isbn,
                   library->books[i].publication_year,
                   library->books[i].is_available ? "Yes" : "No");
        }
    }
}

void update_availability(Library* library) {
    char isbn[20];
    printf("Enter ISBN of the book to update availability: ");
    getchar(); 
    fgets(isbn, sizeof(isbn), stdin);
    isbn[strcspn(isbn, "\n")] = 0; 

    for (int i = 0; i < library->count; i++) {
        if (strcmp(library->books[i].isbn, isbn) == 0) {
            library->books[i].is_available = !library->books[i].is_available; 
            printf("Availability updated to: %s\n", library->books[i].is_available ? "Available" : "Checked out");
            return;
        }
    }
    printf("Book not found!\n");
}

int main() {
    Library library = { .count = 0 };
    int choice;

    do {
        printf("\nLibrary Menu:\n");
        printf("1. Add Book\n");
        printf("2. Search Books\n");
        printf("3. Update Availability\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_book(&library);
                break;
            case 2:
                search_books(&library);
                break;
            case 3:
                update_availability(&library);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

