#include <stdio.h>
#include <string.h>

#define MAX_DEPARTMENTS 5
#define MAX_COURSES 10
#define MAX_STUDENTS 50
struct Student {
    int studentID;
    char name[50];
};
struct Instructor {
    int instructorID;
    char name[50];
};
struct Course {
    int courseID;
    char courseName[50];
    struct Instructor instructor;
    struct Student students[MAX_STUDENTS];
    int studentCount;
};
struct Department {
    int departmentID;
    char departmentName[50];
    struct Course courses[MAX_COURSES];
    int courseCount;
};
struct Department departments[MAX_DEPARTMENTS];
int departmentCount = 0;
void addDepartment();
void addCourse();
void addStudent();
void viewDepartments();
void viewCourses();
void viewStudents();

int main() {
    int choice;

    do {
        printf("\nUniversity Management System\n");
        printf("1. Add Department\n");
        printf("2. Add Course to a Department\n");
        printf("3. Add Student to a Course\n");
        printf("4. View All Departments\n");
        printf("5. View Courses in a Department\n");
        printf("6. View Students in a Course\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addDepartment(); break;
            case 2: addCourse(); break;
            case 3: addStudent(); break;
            case 4: viewDepartments(); break;
            case 5: viewCourses(); break;
            case 6: viewStudents(); break;
            case 7: printf("Exiting program. Goodbye!\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
void addDepartment() {
    if (departmentCount >= MAX_DEPARTMENTS) {
        printf("Maximum number of departments reached.\n");
        return;
    }
    printf("Enter Department ID: ");
    scanf("%d", &departments[departmentCount].departmentID);
    printf("Enter Department Name: ");
    scanf(" %[^\n]s", departments[departmentCount].departmentName);
    departments[departmentCount].courseCount = 0; 
    departmentCount++;
    printf("Department added successfully!\n");
}
void addCourse() {
    if (departmentCount == 0) {
        printf("No departments available. Add a department first.\n");
        return;
    }

    int deptID;
    printf("Enter Department ID to add the course: ");
    scanf("%d", &deptID);

    for (int i = 0; i < departmentCount; i++) {
        if (departments[i].departmentID == deptID) {
            if (departments[i].courseCount >= MAX_COURSES) {
                printf("Maximum number of courses reached for this department.\n");
                return;
            }
            struct Course* course = &departments[i].courses[departments[i].courseCount];
            printf("Enter Course ID: ");
            scanf("%d", &course->courseID);
            printf("Enter Course Name: ");
            scanf(" %[^\n]s", course->courseName);
            printf("Enter Instructor ID: ");
            scanf("%d", &course->instructor.instructorID);
            printf("Enter Instructor Name: ");
            scanf(" %[^\n]s", course->instructor.name);
            course->studentCount = 0; 
            departments[i].courseCount++;
            printf("Course added successfully!\n");
            return;
        }
    }
    printf("Department not found.\n");
}
void addStudent() {
    if (departmentCount == 0) {
        printf("No departments available. Add a department first.\n");
        return;
    }

    int deptID, courseID;
    printf("Enter Department ID: ");
    scanf("%d", &deptID);

    for (int i = 0; i < departmentCount; i++) {
        if (departments[i].departmentID == deptID) {
            printf("Enter Course ID to add the student: ");
            scanf("%d", &courseID);

            for (int j = 0; j < departments[i].courseCount; j++) {
                if (departments[i].courses[j].courseID == courseID) {
                    if (departments[i].courses[j].studentCount >= MAX_STUDENTS) {
                        printf("Maximum number of students reached for this course.\n");
                        return;
                    }

                    struct Student* student = &departments[i].courses[j].students[departments[i].courses[j].studentCount];

                    printf("Enter Student ID: ");
                    scanf("%d", &student->studentID);
                    printf("Enter Student Name: ");
                    scanf(" %[^\n]s", student->name);
                    departments[i].courses[j].studentCount++;
                    printf("Student added successfully!\n");
                    return;
                }
            }

            printf("Course not found.\n");
            return;
        }
    }
    printf("Department not found.\n");
}
void viewDepartments() {
    if (departmentCount == 0) {
        printf("No departments available.\n");
        return;
    }

    printf("\nDepartments:\n");
    for (int i = 0; i < departmentCount; i++) {
        printf("ID: %d, Name: %s\n", departments[i].departmentID, departments[i].departmentName);
    }
}
void viewCourses() {
    if (departmentCount == 0) {
        printf("No departments available.\n");
        return;
    }
    int deptID;
    printf("Enter Department ID to view courses: ");
    scanf("%d", &deptID);

    for (int i = 0; i < departmentCount; i++) {
        if (departments[i].departmentID == deptID) {
            if (departments[i].courseCount == 0) {
                printf("No courses available in this department.\n");
                return;
            }

            printf("\nCourses in Department %s:\n", departments[i].departmentName);
            for (int j = 0; j < departments[i].courseCount; j++) {
                printf("Course ID: %d, Name: %s, Instructor: %s\n",
                       departments[i].courses[j].courseID, departments[i].courses[j].courseName,
                       departments[i].courses[j].instructor.name);
            }
            return;
        }
    }
    printf("Department not found.\n");
}
void viewStudents() {
    if (departmentCount == 0) {
        printf("No departments available.\n");
        return;
    }

    int deptID, courseID;
    printf("Enter Department ID: ");
    scanf("%d", &deptID);

    for (int i = 0; i < departmentCount; i++) {
        if (departments[i].departmentID == deptID) {
            printf("Enter Course ID to view students: ");
            scanf("%d", &courseID);

            for (int j = 0; j < departments[i].courseCount; j++) {
                if (departments[i].courses[j].courseID == courseID) {
                    if (departments[i].courses[j].studentCount == 0) {
                        printf("No students enrolled in this course.\n");
                        return;
                    }

                    printf("\nStudents in Course %s:\n", departments[i].courses[j].courseName);
                    for (int k = 0; k < departments[i].courses[j].studentCount; k++) {
                        printf("Student ID: %d, Name: %s\n",
                               departments[i].courses[j].students[k].studentID,
                               departments[i].courses[j].students[k].name);
                    }
                    return;
                }
            }

            printf("Course not found.\n");
            return;
        }
    }

    printf("Department not found.\n");
}

