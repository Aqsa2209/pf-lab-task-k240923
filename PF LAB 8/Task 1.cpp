#include<stdio.h>
int main(){
	int matrix[3][3];
	int rowSum[3]={0}, colSum[3]={0};
	printf("Enter elements for matrix 3x3\n:");
	for(int i=0; i<3; i++){
	for(int j=0; j<3; j++ ){
		printf("Element [%d][%d]:", i, j);
		scanf("%d", &matrix[i][j]);
	   }
			}
		for (int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				rowSum[i]+= matrix[i][j];
				colSum[j]+=matrix[i][j];
			}
		}
		printf("\nScore of each participant across all activities:\n");
		for (int i=0; i<3; i++){
			printf("Score of Participant%d: %d\n", i+1, rowSum[i]);
		}
		
			printf("Total Score of each activity across all activities:\n");
			for(int j=0; j<3; j++){
			printf("Score for activity %d: %d\n", j+1, colSum[j]);	
			}
		
			return 0;
}
