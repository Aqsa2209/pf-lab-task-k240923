#include<stdio.h>
int main(){


int grades[4][4];
printf("Enter grades of 4 students across 4 subjects:\n");
	for(int i=0; i<4; i++){
	for(int j=0; j<4; j++ ){
		printf("Grade[%d][%d]:", i, j);
		scanf("%d", &grades[i][j]);
}
}
	for(int i=0; i<4; i++){
	for(int j=0; j<4; j++ ){
		if( grades[i][j]<0){
			grades[i][j]=0;
		}
	}
}
 printf("\nUpdated grades matrix:\n");
 for(int i=0; i<4; i++){
	for(int j=0; j<4; j++ ){
		printf("%d ", grades[i][j]);
}
printf("\n");
}

return 0;
}
