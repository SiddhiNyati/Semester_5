#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Emp {
    int id;
    char name[50];
    struct Emp *next;  
};

struct Dept {
    char name[50];
    struct Emp *empList; 
};

void addEmp(struct Dept *dept);
void rtrvEmp(struct Dept *dept);
void rtrvEmpInfo(struct Dept *dept); 

void addEmp(struct Dept *dept) {
    struct Emp *newEmp = (struct Emp *)malloc(sizeof(struct Emp));
    printf("Enter Employee ID: ");
    scanf("%d", &newEmp->id);
    printf("Enter Employee Name: ");
    scanf("%s", newEmp->name);
    newEmp->next = dept->empList;  
    dept->empList = newEmp;
}

void rtrvEmp(struct Dept *dept) {
    struct Emp *current = dept->empList;
    if (current == NULL) {
        printf("No employees in %s department.\n", dept->name);
        return;
    }
    printf("Employees in %s department:\n", dept->name);
    while (current != NULL) {
        printf("ID: %d, Name: %s\n", current->id, current->name);
        current = current->next;
    }
}

void rtrvEmpInfo(struct Dept *dept) {
    int empId;
    printf("Enter Employee ID to retrieve: ");
    scanf("%d", &empId);
    struct Emp *current = dept->empList;
    while (current != NULL) {
        if (current->id == empId) {
            printf("Employee found - ID: %d, Name: %s\n", current->id, current->name);
            return;
        }
        current = current->next;
    }
    printf("Employee with ID %d not found in %s department.\n", empId, dept->name);
}

int main() {
    int numDept;
    
    printf("Enter the number of departments: ");
    scanf("%d", &numDept);
    
    struct Dept *dept = (struct Dept*)malloc(numDept * sizeof(struct Dept));

    for (int i = 0; i < numDept; i++) {
        printf("Enter name of department %d: ", i + 1);
        scanf("%s", dept[i].name);
        dept[i].empList = NULL; 
    }
    
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add Employee\n");
        printf("2. Retrieve All Employees from a Department\n");
        printf("3. Retrieve Specific Employee Details\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                    int deptIndex;
                    printf("Enter department index (0 to %d): ", numDept - 1);
                    scanf("%d", &deptIndex);
                    if (deptIndex >= 0 && deptIndex < numDept) {
                        addEmp(&dept[deptIndex]);
                    } else {
                        printf("Invalid department index!\n");
                    }
                }
                break;
            case 2: {
                    int deptIndex;
                    printf("Enter department index (0 to %d): ", numDept - 1);
                    scanf("%d", &deptIndex);
                    if (deptIndex >= 0 && deptIndex < numDept) {
                        rtrvEmp(&dept[deptIndex]);
                    } else {
                        printf("Invalid department index!\n");
                    }
                }
                break;
            case 3: {
                    int deptIndex;
                    printf("Enter department index (0 to %d): ", numDept - 1);
                    scanf("%d", &deptIndex);
                    if (deptIndex >= 0 && deptIndex < numDept) {
                        rtrvEmpInfo(&dept[deptIndex]); 
                    } else {
                        printf("Invalid department index!\n");
                    }
                }
                break;
            case 4:
                printf("Exiting\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);
    
    for (int i = 0; i < numDept; i++) {
        struct Emp *current = dept[i].empList;
        while (current != NULL) {
            struct Emp *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(dept);
    
    return 0;
}