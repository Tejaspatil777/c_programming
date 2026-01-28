#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
/*Given an unsorted array and a target sum, write a program to find all pairs
in the array whose sum is equal to the given target.
What is the time complexity of your approach for finding all pairs in the
unsorted array that sum to the target value?
Input: arr = [1, 5, 7, -1, 5], sum = 6
Output: [(1, 5), (7, -1), (1, 5)]*/
int main(){
int arr[100], n,sum;
printf("Enter size of an array : ");
scanf("%d",&n);
printf("Enter elements of an array --->");
for (int i = 0; i < n; i++) scanf("%d",&arr[i]);
printf("Now enter your target sum : ");
scanf("%d",&sum);
for (int i = 0; i < n; i++)
{
    for (int j = i+1; j < n; j++)
    {
        if(arr[i]+arr[j] == sum) printf("(%d,%d)",arr[i],arr[j]);
    }
}
return 0;
}