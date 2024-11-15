#include<stdio.h>
typedef struct Box{
	int weight;
	struct Box*nested;
}Box;
int calculate_total_weight(Box*box){
	if(box==NULL) return 0;
	return box->weight+calculate_total_weight(box->nested);	
}
int main(){
	Box nestedBox={2, NULL};
	Box mainBox={10, &nestedBox};
	printf("Total weight: %d\n", calculate_total_weight(&mainBox));
	return 0;
}