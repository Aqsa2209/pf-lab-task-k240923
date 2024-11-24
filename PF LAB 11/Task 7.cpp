#include <stdio.h>
#include <string.h>

#define MAX_DEPARTMENTS 10
#define MAX_COURSES 20

// Define structure for a Course
struct Course {
    char courseID[10];
    char courseName[50];
    char instructorName[50];
    int credits;
};

// Define structure for a Department
struct Department {
    char departmentName[50];
    struct Course courses[MAX_COURSES];
    int courseCount;
};

// Declare an array of departments and a counter for the number of departments
struct Department departments[MAX_DEPARTMENTS];
int departmentCount = 0;

// Function to add a new department
void addDepartment() {
    if (departmentCount >= MAX_DEPARTMENTS) {
        printf("Cannot add more departments. Maximum limit reached.\n");
        return;
    }

    printf("Enter department name: ");
    scanf(" %[^\n]s", departments[departmentCount].departmentName);
    departments[departmentCount].courseCount = 0; // Initialize course count to 0
    departmentCount++;
    printf("Department added successfully!\n");
}

// Function to add a new course to a department
void addCourse() {
    if (departmentCount == 0) {
        printf("No departments available. Add a department first.\n");
        return;
    }

    printf("Enter the department name to add a course to: ");
    char deptName[50];
    scanf(" %[^\n]s", deptName);

    for (int i = 0; i < departmentCount; i++) {
        if (strcmp(departments[i].departmentName, deptName) == 0) {
            if (departments[i].courseCount >= MAX_COURSES) {
                printf("Cannot add more courses to this department. Maximum limit reached.\n");
                return;
            }

            int courseIndex = departments[i].courseCount;
            printf("Enter course ID: ");
            scanf(" %[^\n]s", departments[i].courses[courseIndex].courseID);
            printf("Enter course name: ");
            scanf(" %[^\n]s", departments[i].courses[courseIndex].courseName);
            printf("Enter instructor name: ");
            scanf(" %[^\n]s", departments[i].courses[courseIndex].instructorName);
            printf("Enter credits: ");
            scanf("%d", &departments[i].courses[courseIndex].credits);

            departments[i].courseCount++;
            printf("Course added successfully!\n");
            return;
        }
    }

    printf("Department not found.\n");
}

// Function to display all departments and their courses
void displayDetails() {
    if (departmentCount == 0) {
        printf("No departments available.\n");
        return;
    }

    for (int i = 0; i < departmentCount; i++) {
        printf("\nDepartment: %s\n", departments[i].departmentName);
        printf("Courses:\n");
        for (int j = 0; j < departments[i].courseCount; j++) {
            struct Course c = departments[i].courses[j];
            printf("  Course ID: %s, Name: %s, Instructor: %s, Credits: %d\n",
                   c.courseID, c.courseName, c.instructorName, c.credits);
        }
    }
}

// Function to calculate the total credits for a department
void calculateTotalCredits() {
    if (departmentCount == 0) {
        printf("No departments available.\n");
        return;
    }

    printf("Enter the department name to calculate total credits: ");
    char deptName[50];
    scanf(" %[^\n]s", deptName);

    for (int i = 0; i < departmentCount; i++) {
        if (strcmp(departments[i].departmentName, deptName) == 0) {
            int totalCredits = 0;
            for (int j = 0; j < departments[i].courseCount; j++) {
                totalCredits += departments[i].courses[j].credits;
            }
            printf("Total credits for department %s: %d\n", deptName, totalCredits);
            return;
        }
    }

    printf("Department not found.\n");
}

// Main function to handle the menu
int main() {
    int choice;

    do {
        printf("\nUniversity Course Enrollment System\n");
        printf("1. Add a Department\n");
        printf("2. Add a Course\n");
        printf("3. Display All Details\n");
        printf("4. Calculate Total Credits for a Department\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addDepartment();
                break;
            case 2:
                addCourse();
                break;
            case 3:
                displayDetails();
                break;
            case 4:
                calculateTotalCredits();
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

