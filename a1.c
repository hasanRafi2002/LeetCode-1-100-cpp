#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Student Structure
struct Student {
    int id;
    char name[50];
    char department[50];
    int semester;
    float cgpa;
};

// Function Prototypes
void adminMenu();
void studentMenu();
void addStudent();
void viewStudent();
void updateStudent();
void deleteStudent();
void viewAllStudents();
void viewOwnDetails(int);

// Main Program — Login Menu
int main() {
    int choice;
    char password[20];
    int studentId;



    while (1) {
        printf("\n===== Student Information Management System =====\n");
        printf("1. Admin Login\n");
        printf("2. Student Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Admin Password: ");
                scanf("%s", password);
                if (strcmp(password, "admin123") == 0) {
                    adminMenu();
                } else {
                    printf("❌ Incorrect Password!\n");
                }
                break;

            case 2:
                printf("Enter your Student ID: ");
                scanf("%d", &studentId);
                viewOwnDetails(studentId);
                break;

            case 3:
                printf("👋 Exiting system... Goodbye!\n");
                exit(0);

            default:
                printf("❌ Invalid choice! Try again.\n");
        }
    }



    return 0;
}






// Admin Menu Function
void adminMenu() {
    int choice;

    do {
        printf("\n===== Admin Menu =====\n");
        printf("1. Add Student\n");
        printf("2. View Student by ID\n");
        printf("3. Update Student\n");
        printf("4. Delete Student\n");
        printf("5. View All Students\n");
        printf("6. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudent();
                break;
            case 3:
                updateStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                viewAllStudents();
                break;
            case 6:
                printf("🔒 Logged out from Admin Panel.\n");
                break;
            default:
                printf("❌ Invalid choice! Try again.\n");
        }

    }while (choice != 6);
}





// Function to Add a New Student (Text Mode)
void addStudent() {
    FILE *fp;
    struct Student s;

    fp = fopen("students.txt", "a");
    if (fp == NULL) {
        printf("❌ Error opening file!\n");
        return;
    }

    printf("\nEnter Student ID: ");
    scanf("%d", &s.id);
    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter Department: ");
    scanf(" %[^\n]", s.department);
    printf("Enter Semester: ");
    scanf("%d", &s.semester);
    printf("Enter CGPA: ");
    scanf("%f", &s.cgpa);

    fprintf(fp, "%d %s %s %d %.2f\n", s.id, s.name, s.department, s.semester, s.cgpa);
    fclose(fp);

    printf("✅ Student added successfully!\n");
}





// Function to View Student by ID (Text Mode)
void viewStudent() {
    FILE *fp;
    struct Student s;
    int id, found = 0;

    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("❌ No student records found!\n");
        return;
    }

    printf("\nEnter Student ID to view: ");
    scanf("%d", &id);

    while (fscanf(fp, "%d %s %s %d %f", &s.id, s.name, s.department, &s.semester, &s.cgpa) != EOF) {
        if (s.id == id) {
            printf("\n--- Student Details ---\n");
            printf("ID: %d\n", s.id);
            printf("Name: %s\n", s.name);
            printf("Department: %s\n", s.department);
            printf("Semester: %d\n", s.semester);
            printf("CGPA: %.2f\n", s.cgpa);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("❌ Student not found!\n");

    fclose(fp);
}





// Function to Update Student by ID
void updateStudent() {
    FILE *fp, *tempFp;
    struct Student s;
    int id, found = 0;

    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("❌ No student records found!\n");
        return;
    }

    tempFp = fopen("temp.txt", "w");
    if (tempFp == NULL) {
        printf("❌ Error creating temporary file!\n");
        fclose(fp);
        return;
    }

    printf("\nEnter Student ID to update: ");
    scanf("%d", &id);

    while (fscanf(fp, "%d %s %s %d %f", &s.id, s.name, s.department, &s.semester, &s.cgpa) != EOF) {
        if (s.id == id) {
            printf("Enter new details for student ID %d:\n", id);

            printf("Name: ");
            scanf(" %[^\n]", s.name);
            printf("Department: ");
            scanf(" %[^\n]", s.department);
            printf("Semester: ");
            scanf("%d", &s.semester);
            printf("CGPA: ");
            scanf("%f", &s.cgpa);

            fprintf(tempFp, "%d %s %s %d %.2f\n", s.id, s.name, s.department, s.semester, s.cgpa);
            found = 1;
        } else {
            fprintf(tempFp, "%d %s %s %d %.2f\n", s.id, s.name, s.department, s.semester, s.cgpa);
        }
    }

    fclose(fp);
    fclose(tempFp);

    if (found) {
        remove("students.txt");
        rename("temp.txt", "students.txt");
        printf("✅ Student ID %d updated successfully!\n", id);
    } else {
        remove("temp.txt");
        printf("❌ Student ID %d not found!\n", id);
    }
}





// Function to Delete Student by ID
void deleteStudent() {
    FILE *fp, *tempFp;
    struct Student s;
    int id, found = 0;

    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("❌ No student records found!\n");
        return;
    }

    tempFp = fopen("temp.txt", "w");
    if (tempFp == NULL) {
        printf("❌ Error creating temporary file!\n");
        fclose(fp);
        return;
    }

    printf("\nEnter Student ID to delete: ");
    scanf("%d", &id);

    while (fscanf(fp, "%d %s %s %d %f", &s.id, s.name, s.department, &s.semester, &s.cgpa) != EOF) {
        if (s.id == id) {
            found = 1;
            // Skip writing this record to temp file -> delete
        } else {
            fprintf(tempFp, "%d %s %s %d %.2f\n", s.id, s.name, s.department, s.semester, s.cgpa);
        }
    }

    fclose(fp);
    fclose(tempFp);

    if (found) {
        remove("students.txt");
        rename("temp.txt", "students.txt");
        printf("✅ Student ID %d deleted successfully!\n", id);
    } else {
        remove("temp.txt");
        printf("❌ Student ID %d not found!\n", id);
    }
}





// Function to View All Students
void viewAllStudents() {
    FILE *fp;
    struct Student s;
    int count = 0;

    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("❌ No student records found!\n");
        return;
    }

    printf("\n===== All Student Records =====\n");
    printf("ID\tName\tDepartment\tSemester\tCGPA\n");

    while (fscanf(fp, "%d %s %s %d %f", &s.id, s.name, s.department, &s.semester, &s.cgpa) != EOF) {
        printf("%d\t%s\t%s\t%d\t\t%.2f\n", s.id, s.name, s.department, s.semester, s.cgpa);
        count++;
    }

    if (count == 0)
        printf("❌ No student records to display!\n");

    fclose(fp);
}






// Function for student to view their own details by ID
void viewOwnDetails(int studentId) {
    FILE *fp;
    struct Student s;
    int found = 0;

    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("❌ No student records found!\n");
        return;
    }

    while (fscanf(fp, "%d %s %s %d %f", &s.id, s.name, s.department, &s.semester, &s.cgpa) != EOF) {
        if (s.id == studentId) {
            printf("\n--- Your Student Details ---\n");
            printf("ID: %d\n", s.id);
            printf("Name: %s\n", s.name);
            printf("Department: %s\n", s.department);
            printf("Semester: %d\n", s.semester);
            printf("CGPA: %.2f\n", s.cgpa);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("❌ No student found with ID %d\n", studentId);

    fclose(fp);
}
