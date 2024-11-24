#include<stdio.h>
#include<stdlib.h>
 int main(){
 	FILE *file;
 	char filename[100];
 	char line [256];
 	int lineNumber=1;
 	printf("Enter file name to open: ");
 	scanf("%s", filename);
 	file= fopen(filename, "r");
 	if(file==NULL){
 		perror("Error opening file");
 		return EXIT_FAILURE;
	}
	while (fgets(line, sizeof(line), file)){
		printf("%d: %s", lineNumber, line);
		lineNumber++;
	}
	fclose(file);
	return EXIT_SUCCESS;
 }

