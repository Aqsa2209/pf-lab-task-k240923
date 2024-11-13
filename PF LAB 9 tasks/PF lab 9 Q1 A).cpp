#include<stdio.h>
int main(){
	int n;
	printf("enter the number:");
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		for(int j=i; j<=n; j++){
			printf(". ");
		}
		for(int k=1; k<=i; k++){
			printf("o");
		}
		printf("\n");
	}
	for(int i=2; i<=n; i++){
		for(int j=1; j<=i; j++){
			printf(". ");
		}
		for(int k=n; k>=i; k--){
			printf("o");
		}
		printf("\n");
	}
}
