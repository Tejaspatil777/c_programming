#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct Student{ 
    char name[50];
    int roll ;
    float marks;
}S;
void writeTo(S *,int);
void readBy(int);
int main(){
int n;
error :
printf("Enter a number of students : ");
scanf("%d",&n);
if(n<3) { 
    printf("Number of students should be atleast 3 -->");
    goto error;
};
S St[n];
writeTo(St,n);
readBy(n);
return 0;
}
void writeTo(S *St,int n){
FILE *fptr = fopen("transaction.dat","wb");
if(!fptr){ 
    printf("FILE NOT FOUND");
    return;
}
for (int i = 0; i < n; i++){
   printf("Enter St[%d] details -> ",i);
   printf("Name : ");
   getchar();
   fgets(St[i].name,50,stdin);
   printf("Roll No. : ");
   scanf("%d",&St[i].roll);
   printf("Marks : ");
   scanf("%f",&St[i].marks);
}
fwrite(St,sizeof(S),n,fptr);
fclose(fptr);
}

void readBy(int n){ 
FILE *fptr = fopen("transaction.dat","rb");
if(!fptr){ 
    printf("FILE NOT FOUND");
    return;
}
S St[n];
fread(St,sizeof(S),n,fptr);
printf("Student Table --->\n");
printf("Name\tRoll\tMarks\n");
for (int i = 0; i < n; i++){
    printf("%s\t%d\t%.2f\n",
               St[i].name, St[i].roll, St[i].marks);
}
fclose(fptr);
}