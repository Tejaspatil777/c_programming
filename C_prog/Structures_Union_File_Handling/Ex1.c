#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
/*Define a structure Student with fields char name[30], int roll_no, and
float marks.
• Input data for n students using an array of structures.
• Write a function to sort the students in descending order of marks.
• Display the sorted list. Comment on how structures can improve
data organization */
struct Student
{
    char name[30];
    int roll_no;
    float marks;
};
void printSortedByMarks(const struct Student arr[],int);
int main(){
    int n ;
    printf("Enter a value of n : ");
    scanf("%d",&n);
struct Student arr[n];
printf("Enter details of students ---->\n");
for (int i = 0; i < n; i++)
{
    printf("Student a[%d] => ", i);
    getchar();
    printf("Name : ");
    fgets(arr[i].name,30,stdin);
    printf("Roll no. : ");
    scanf("%d", &arr[i].roll_no);
    printf("Marks : ");
    scanf("%f", &arr[i].marks);
}
printSortedByMarks(arr,n);
return 0;
}
void printSortedByMarks(const struct Student arr[], int n) {
    int idx[n];

    // Step 1: Initialize index array
    for (int i = 0; i < n; i++)
        idx[i] = i;

    // Step 2: Sort indexes based on marks (Bubble Sort)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[idx[j]].marks < arr[idx[j + 1]].marks) {
                int temp = idx[j];
                idx[j] = idx[j + 1];
                idx[j + 1] = temp;
            }
        }
    }

    // Step 3: Print using sorted indexes
    printf("\nStudents sorted by marks (original array unchanged):\n");
    for (int i = 0; i < n; i++) {
        int k = idx[i];
        printf("Name: %s", arr[k].name);
        printf("Roll No: %d\n", arr[k].roll_no);
        printf("Marks: %.2f\n\n", arr[k].marks);
    }
}
