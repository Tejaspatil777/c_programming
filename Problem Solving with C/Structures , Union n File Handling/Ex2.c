#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
/*Define a structure Contact with the following fields: char name[30]; char
phone[15]; char email[50];
• Write a C program to input and store details of 3 contacts using an
array of structures. Save all records to a binary file using the fwrite()
function. Read and display the records from the binary file using
fread().
• Briefly explain how structured data can be stored and retrieved using
binary files in C. Discuss the advantages of using fwrite()/fread() over
text file I/O for structure persistence.*/
typedef struct Contact{ 
char name[30];
char phone[25];
char email[50];
}C;

int main(){
C det[3];
printf("Enter Contact details --->\n");
for (int i = 0; i < 3; i++){   
printf("Contact No. det[%d] : ",i);
printf("Name : ");
fgets(det[i].name,30,stdin);
printf("Phone No. : ");
fgets(det[i].phone,15,stdin);
printf("Email : ");
fgets(det[i].email,50,stdin);
}
FILE *fptr = fopen("contact.dat","wb+");
    if(!fptr){
        printf("File does'nt exist");
        exit(1);
    }
fwrite(det,sizeof(C),3,fptr);
rewind(fptr);
C det1[3];
fread(det1,sizeof(C),3,fptr);
for (int i = 0; i < 3; i++){
    printf("Contact detail Number det1[%d]", i);
    printf("Name : %s",det1[i].name);
    printf("Phone : %s ",det1[i].phone);
    printf("Email : %s",det1[i].email);
}
fclose(fptr);
return 0;
}