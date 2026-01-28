#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
/*Write a C program that accepts two command-line arguments:
A filename
A search word
Tasks
• The program should open the specified file and count how
many times the given word appears in the file, regardless of
case.
• Display the count to the user.*/
int main(int argc,char* argv[]){
if(argc == 1){ 
    printf("NO ANY COMMAND LINE ARGUMENTS PROVIDED");
    exit(1);
}
else if(argc != 3){ 
printf("Exact two command line arguments allowed");
exit(1);
}
else if(argc == 3){
FILE *fptr = fopen(argv[1],"r");
if(!fptr){ 
    printf("FILE NOT FOUND");
    exit(1);
}
char str[15];
while (feof(fptr) == 0){
  fscanf(fptr,"%s",str);
  if(strcmp(argv[2],str) == 1){ 
    printf("Word Found Succesfully");
    fclose(fptr);
    return 0;
  }
}
printf("Word Not Found");
fclose(fptr);
}
return 0;
}