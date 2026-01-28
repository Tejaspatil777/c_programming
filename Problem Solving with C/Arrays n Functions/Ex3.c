#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
/*Write a C program that takes an integer array and a shift value as input.
Implement a function to perform a circular shift on the array elements*/
void cirShift(int *arr, int size , int sv){ 
    sv = sv % size; 
    for (int i = 1; i <= sv; i++)
    {   
        int temp = arr[size - 1];
        for (int j = size-1; j > 0; j--)
        {
            arr[j] = arr[j-1];
        }
        arr[0] = temp;
    }
}
int main(){
int arr[100] , size , sv ;
printf("Enter size of an array : ");
scanf("%d",&size);
printf("Enter Elements of an array : ");
for( int i=0 ; i<size ; i++) scanf("%d",&arr[i]);
printf("Enter shift value : ");
scanf("%d", &sv);
cirShift(arr,size,sv);
printf("After Shifting : ");
for( int i=0 ; i<size ; i++) printf("%d ",arr[i]);
return 0;
}