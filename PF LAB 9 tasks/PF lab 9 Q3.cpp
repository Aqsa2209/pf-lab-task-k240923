#include <stdio.h>
#include <string.h>

int main() {
    const char *pre_stored_username = "admin";
    const char *pre_stored_password = "1234";

    char entered_username[50];
    char entered_password[50];

    printf("Enter username: ");
    fgets(entered_username, sizeof(entered_username), stdin);
    entered_username[strcspn(entered_username, "\n")] = 0;

    printf("Enter password: ");
    fgets(entered_password, sizeof(entered_password), stdin);
    entered_password[strcspn(entered_password, "\n")] = 0;

    if (strcmp(entered_username, pre_stored_username) == 0 &&
        strcmp(entered_password, pre_stored_password) == 0) {
        printf("Access granted\n");
    } else {
        printf("Access denied\n");
    }

    return 0;
}
