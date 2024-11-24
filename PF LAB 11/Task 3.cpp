#include <stdio.h>
#include <ctype.h> 

void copyFileWithUppercase(const char* sourceFile, const char* destinationFile) {
    FILE *source, *destination;
    char ch;
    source = fopen(sourceFile, "r");
    if (source == NULL) {
        printf("Error: Could not open source file %s\n", sourceFile);
        return;
    }
    destination = fopen(destinationFile, "w");
    if (destination == NULL) {
        printf("Error: Could not open destination file %s\n", destinationFile);
        fclose(source);
        return;
    }
    while ((ch = fgetc(source)) != EOF) {
        ch = toupper(ch);
        fputc(ch, destination);
    }

    printf("File copied successfully with lowercase characters converted to uppercase.\n");
    fclose(source);
    fclose(destination);
}

int main() {
    char sourceFile[100], destinationFile[100];
    printf("Enter the name of the source file: ");
    scanf("%s", sourceFile);
    printf("Enter the name of the destination file: ");
    scanf("%s", destinationFile);
    copyFileWithUppercase(sourceFile, destinationFile);

    return 0;
}

