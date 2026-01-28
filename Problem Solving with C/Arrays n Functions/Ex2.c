#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
/*Write a C program that takes an array of integers as input and
reverses it using a function. */
void revArray(int *arr,int size){
    for(int i=0 , j = size -1 ; i < j; i++ , j--){ 
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    return;
}
int main(){
int arr[100] , size ;
printf("Enter size of an array : ");
scanf("%d",&size);
printf("Enter Elements of an array : ");
for( int i=0 ; i<size ; i++) scanf("%d",&arr[i]);
revArray(arr,size);
printf("Reverse of an array : ");
for( int j=0 ; j<size ; j++) printf("%d ", arr[j]);
return 0;
}