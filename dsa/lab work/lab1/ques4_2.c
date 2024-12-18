//call by reference
#include <stdio.h>

typedef struct {
    char name[100];
    int rollNumber;
    float marks;
} Student;

void getStudentWithHighestMarks(Student students[], int n, Student *topStudent) {
    *topStudent = students[0];
    for (int i = 1; i < n; i++) {
        if (students[i].marks > topStudent->marks) {
            *topStudent = students[i];
        }
    }
}

int main() {
    Student students[2];

    for (int i = 0; i < 2; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]%*c", students[i].name); 
        printf("Roll Number: ");
        scanf("%d", &students[i].rollNumber);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
        printf("\n");
    }

    Student topStudent;

    getStudentWithHighestMarks(students, 2, &topStudent);

    printf("Student with the highest marks:\n");
    printf("Name: %s\n", topStudent.name);
    printf("Roll Number: %d\n", topStudent.rollNumber);
    printf("Marks: %.2f\n", topStudent.marks);

    return 0;
}