#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
/*Create a program that prints the following pattern using nested for
loops:*/
int main(){
for(int i=1 ; i<=5 ; i++){ 
    for(int j=1 ; j<=i ; j++)
    printf("* ");
printf("\n");
}
return 0;
}