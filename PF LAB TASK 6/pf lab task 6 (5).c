#include<stdio.h>
int main (){
	int num, count=0;
	printf("Enter a Number:");
	scanf("%d", num);
	for (int i=2; i<=num; i++)
	{
		if num(num%i==0){
			count= count+1;
		}
		
	} if (count==0){
		printf("%d is a prime number", num);
	} else{
		printf("%d is not a prime number", num);
		
	}return 0;
}
