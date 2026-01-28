#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
/*Write a C program that identifies and prints the longest commandline argument, excluding the program name itself (argv[0]). If
multiple arguments have the same maximum length, the first one
should be printed.
• Use argc and argv[] to process command-line arguments.
• Ignore argv[0], which contains the program name.
• If no additional arguments are supplied, display a message
like: No command-line arguments provided.*/
int main(int argc,char* argv[]){
if(argc == 1){ 
    printf("NO COMMAND LINE ARGUMENTS PROVIDED");
}
char temp[30];
strcpy(temp,argv[1]);
for (int i = 2; i < argc; i++){
if(strlen(temp)<strlen(argv[i])) strcpy(temp,argv[i]);
}
printf("Longest command line argument : %s",temp);
return 0;
}