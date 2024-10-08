#include<stdio.h>
int main() {
	int num, count, fact =1;
	printf("Enter a positive integer to find its Factorial:");
	scanf("%d", &num);
	if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return 1;
} for (count=1; count<=num; count++) {
	fact= fact*count;
}
  printf("Factorial of %d is %d\n", num, fact);
  return 0;
}
