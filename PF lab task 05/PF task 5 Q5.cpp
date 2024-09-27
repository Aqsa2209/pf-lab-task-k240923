#include<stdio.h>
int main(){
	float percentage;
	printf("Enter the percentage");
	scanf("%f", &percentage);
	char grade= (percentage>=90)? 'A': (percentage>=80)? 'B': (percentage>=70)?'C': (percentage>=60)?'D':'F';
	printf("The grade is: %c/n", grade);
	return 0;

}
