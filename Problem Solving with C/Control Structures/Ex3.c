#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
/*Write a C program to find the LCM of two numbers and then verify
it by listing several common multiples.*/
int main(){
int n1,n2,max;
    printf("Enter any two numbers : \n");
    scanf("%d %d", &n1, &n2);
    int step = max = fmax(n1,n2);
    while (1){
     if(max % n1 == 0 && max % n2 == 0){
     printf("LCM of %d & %d is %d", n1 , n2 , max);
     return 0;
    }
    max+=step;
    }
}