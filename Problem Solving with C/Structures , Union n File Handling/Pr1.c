#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
/*Problem Description
• Develop a C program Each student has the following attributes:
• Student ID: A unique identifier for each student (integer).
• Name: The name of the student (string).
• Grade: The grade of the student (float).
• Courses: A list of courses the student is enrolled in (variablelength array of strings or a structure).
• Use a structure to store each student’s information.
• Use a union to store the course data in a variable-length format.
• Store the student information in a binary file for permanent storage.
• Implement functions to:
• Add a new student record.
• Display student information.
• Modify student information.
• Save the updated records to a file.
Tasks
• Define the structure and union to store student data and courses.
• Write functions to:
• Add a new student to the file.
• Display student details.
• Modify a student's record.
• Use file handling to read and write student records from and to a
binary file.Solution Hints
ü Create structure with student information
ü Create separate functions for every operation
ü Store the data in raw format*/
typedef union Courses{
    int count;
    char singleCourse[30];
    char multiCourses[5][30];
}C;
typedef struct {
    int sId;
    char name[30];
    float marks;
    C c;
}S;
void addSt(){ 
    S s;
    printf("Enter student details ---->\n");
    printf("Enter Sid : ");
    scanf("%d", &s.sId);
    printf("Enter name : ");
    getchar();
    fgets(s.name,sizeof(s.name),stdin);
    printf("Enter Marks : ");
    scanf("%f", &s.marks);
    printf("Enter number of courses : ");
    scanf("%d", &s.c.count);
    if(s.c.count==1) { 
        printf("Enter a course name : ");
        getchar();
        fgets(s.c.singleCourse,30,stdin);
    }
    else if (s.c.count > 0 && s.c.count <= 5){
        for (int i = 0; i < s.c.count; i++){
            printf("Enter course name number %d : ",i);
            getchar();
            fgets(&s.c.multiCourses[i][30],30,stdin);
        }
    }
    else printf("Invalid Courses ----> "); 
    FILE *fptr = fopen("student.dat","wb");
    if(!fptr){ 
        printf("FILE NOT FOUND\n");
        return;
    }
    fwrite(&s,sizeof(S),1,fptr);
    fclose(fptr);
}
void modifySt(){ 
    FILE *fptr = fopen("student.dat","rb+");
    if(!fptr){ 
        printf("FILE NOT FOUND\n");
        return;
    }
    int Sid;
    printf("Enter StudentID : ");
    scanf("%d",&Sid);
    S s;
    while(fread(&s,sizeof(S),1,fptr) == 1){ 
        if(s.sId == Sid){ 
            printf("Modify record of student %d\n", Sid);
    printf("Enter Sid : ");
    scanf("%d", &s.sId);
    printf("Enter name : ");
    getchar();
    fgets(s.name,30,stdin);
    printf("Enter Marks : ");
    scanf("%f", &s.marks);
    printf("Enter number of courses : ");
    scanf("%d", &s.c.count);
    if(s.c.count==1) { 
        printf("Enter a course name : ");
        getchar();
        fgets(s.c.singleCourse,30,stdin);
    }
    else if (s.c.count > 0 && s.c.count <= 5){
        for (int i = 0; i < s.c.count; i++){
            printf("Enter course name number %d",i);
            getchar();
            fgets(&s.c.multiCourses[i][30],30,stdin);
        }
    }
    else printf("Invalid Courses ----> "); 
    fseek(fptr,-sizeof(S),SEEK_CUR);
    fwrite(&s,sizeof(S),1,fptr);
    printf("Record updated successfully\n");
    break;
    }
    }
    fclose(fptr);
}
void displaySt(){ 
    FILE *fptr = fopen("student.dat","rb+");
    if(!fptr){ 
        printf("FILE NOT FOUND");
        return;
    }
    S s;
    printf("StudentID\tName\tMarks\tCourseSize\n");
    while(fread(&s,sizeof(S),1,fptr) == 1){ 
    printf("%d\t%s\t%f\t%d",s.sId,s.name,s.marks,s.c.count);
    if(s.c.count==1) { 
        printf("Course name : %s",s.c.singleCourse);
    }
    else if (s.c.count > 0 && s.c.count <= 5){
        for (int i = 0; i < s.c.count; i++){
            printf("Courses name number %d : %s",i,s.c.multiCourses[i]);
        }
    }
    else printf("No course"); 
    }
        fclose(fptr);
}

int main(){
printf("Select an operation you want to perform --->\n");
printf("Add a new student record => 1\n");
printf("Modify a student record => 2\n");
printf("Display a student records => 3\n");
printf("To exit => 0\n");
int x ;
do{
printf("Enter an operation value : ");
scanf("%d", &x);
switch (x){
    case 1 : addSt();
    break;
    case 2 : modifySt();
    break;
    case 3 : displaySt();
    break;
default:
printf("Invalid operation -->\n");
    break;
}
}while(x);
return x;
}