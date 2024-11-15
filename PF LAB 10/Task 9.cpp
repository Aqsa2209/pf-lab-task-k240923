#include <stdio.h>
struct Employee {
    int id;                
    char name[50];        
    char department[50];  
    float salary;          
};

int main() {
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    struct Employee employees[n];
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for employee %d:\n", i + 1);

        printf("Employee ID: ");
        scanf("%d", &employees[i].id);
        printf("Name: ");
        scanf(" %[^\n]", employees[i].name); 
        printf("Department: ");
        scanf(" %[^\n]", employees[i].department); 
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
    }
    printf("\nEmployee Details:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s, Department: %s, Salary: $%.2f\n",
               employees[i].id, employees[i].name, employees[i].department, employees[i].salary);
    }
    return 0;
}
