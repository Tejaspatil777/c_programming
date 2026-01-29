#include<stdio.h>
/*Design a C program that prints all command-line arguments in reverse
order, excluding the program name. Discuss what the program should do
if no arguments (other than the program name) are passed. How does the
handling of argv[0] differ from other elements?*/
int main(int argc , char* argv[]){
    if(argc == 1){ 
         printf("NO COMMAND LINE ARGUMENTS PROVIDED");
    }
for (int i = argc - 1; i > 0 ; i--){
    printf("argv[%d] = %s\n",i,argv[i]);
}
return 0;
}