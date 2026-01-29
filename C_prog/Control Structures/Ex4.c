#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(){
int n ;
unsigned int Sum = 0 ;
printf("Enter a number : ");
scanf("%d", &n);
for(int i=1 ; i<=n ; i++){ 
    Sum+=i;
}
printf("Sum of first n natural numbers : %u", Sum);
return 0;
}