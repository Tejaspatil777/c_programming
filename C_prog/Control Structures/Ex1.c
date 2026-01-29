#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
/*Write a program that generates and displays the multiplication table for a
number entered by the user using a for loop.*/
int main(){
int n ;
printf("Enter a number : ");
scanf("%d",&n);
for(int i=1 ; i<=10 ; i++){
printf("%d * %d = %u\n",n,i,n*i);
}
return 0;
}