#include <stdio.h>
#include <string.h>

int main() {
    const char *students[5] = {
        "Aqsa",
        "Harry",
        "Rafia",
        "Ayesha",
        "John"
    };

    char input_name[50];
    int found = 0; 
    printf("Enter a name: ");
    fgets(input_name, sizeof(input_name), stdin);
    input_name[strcspn(input_name, "\n")] = 0;

    for (int i = 0; i < 5; i++) {
        if (strcmp(input_name, students[i]) == 0) {
            found = 1; 
            break; 
        }
    }

    if (found) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    return 0;
}
