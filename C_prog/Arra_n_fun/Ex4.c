#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
/*Write a C program that takes an integer array as input and finds the
second largest element using a function.*/
void secLargest(int *arr, int size){ 
    if (size < 2) {
        printf("Second largest element does not exist\n");
        return;
    }
int max , secMax;
if(arr[0] >= arr[1]) {
    max = arr[0];
    secMax = arr[1];
}
else{
    max = arr[1];
    secMax = arr[0];
}
for (int  i = 2; i < size; i++)
{
    if(secMax < arr[i]){ 
        if(arr[i] > max){ 
            secMax = max;
            max = arr[i];
        }
        else secMax = arr[i];
    }
}
printf("Second Largest : %d", secMax);
}
int main(){
int arr[100] , size ;
printf("Enter size of an array : ");
scanf("%d",&size);
printf("Enter Elements of an array : ");
for( int i=0 ; i<size ; i++) scanf("%d",&arr[i]);
secLargest(arr, size);
return 0;
}