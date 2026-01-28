#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
/*Write a C program that takes an array of integers as input and
finds the smallest element using a function.*/
void minElement(int *arr, int size){ 
int min = arr[0];
for(int i = 1 ; i<size ; i++){ 
    if(min > arr[i]) min = arr[i];
    printf("Minimum Element of an array : %d", min);
    return ;
}
}
int main(){
int arr[100] , size ;
printf("Enter size of an array : ");
scanf("%d",&size);
printf("Enter Elements of an array : ");
for( int i=0 ; i<size ; i++) scanf("%d",&arr[i]);
minElement(arr,size);
return 0;
}