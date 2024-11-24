#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100
struct Employee {
    char name[50];
    char dob[15];
    int employeeID;
    char department[30];
    float salary;
};
struct Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;
void addEmployee() {
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("Cannot add more employees, storage is full.\n");
        return;
    }
    printf("Enter Employee Name: ");
    scanf(" %[^\n]s", employees[employeeCount].name);
    printf("Enter Date of Birth (dd-mm-yyyy): ");
    scanf(" %[^\n]s", employees[employeeCount].dob);
    printf("Enter Employee ID: ");
    scanf("%d", &employees[employeeCount].employeeID);
    printf("Enter Department: ");
    scanf(" %[^\n]s", employees[employeeCount].department);
    printf("Enter Salary: ");
    scanf("%f", &employees[employeeCount].salary);
    employeeCount++;
    printf("Employee added successfully!\n");
}
void deleteEmployee() {
    int id, found = 0;
    printf("Enter Employee ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].employeeID == id) {
            found = 1;
            for (int j = i; j < employeeCount - 1; j++) {
                employees[j] = employees[j + 1];
            }
            employeeCount--;
            printf("Employee with ID %d deleted successfully.\n", id);
            break;
        }
    }
    if (!found) {
        printf("Employee with ID %d not found.\n", id);
    }
}
void displayEmployees() {
    if (employeeCount == 0) {
        printf("No employees to display.\n");
        return;
    }

    printf("\nEmployee List:\n");
    for (int i = 0; i < employeeCount; i++) {
        printf("Name: %s\n", employees[i].name);
        printf("Date of Birth: %s\n", employees[i].dob);
        printf("Employee ID: %d\n", employees[i].employeeID);
        printf("Department: %s\n", employees[i].department);
        printf("Salary: %.2f\n", employees[i].salary);
    }
}
int main() {
    int choice;

    do {
        printf("\nEmployee Management System\n");
        printf("1. Add an Employee\n");
        printf("2. Delete an Employee\n");
        printf("3. Display All Employees\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                deleteEmployee();
                break;
            case 3:
                displayEmployees();
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

