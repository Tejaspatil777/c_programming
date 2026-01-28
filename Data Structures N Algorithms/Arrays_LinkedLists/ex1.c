#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
/*Suppose you are given an array of integers and a string as input.
Perform the following tasks:
a) Write a recursive function to find the maximum value in the
array without using the in-built function.
b) Count the number of vowels in the given string using an
iterative approach.*/
int maxArr(int arr[],int n){ 
if(n == 1) return arr[n-1];
int max = maxArr(arr,n-1);
max = (max < arr[n-1])?arr[n-1]:max;
return max;
}
void vowStr(char str[]){ 
    int count = 0;
    for (int i = 0; str[i]!='\0'; i++){
        char ch = tolower(str[i]);
        if(ch == 'a'||ch == 'e'||ch == 'i'||ch == 'o'||ch == 'u') count++;
    }
    printf("Total vowels in string : %d",count);
}
int main(){
int arr[101],n;
printf("Enter size of an array : ");
scanf("%d",&n);
for (int i = 0; i < n; i++){
    printf("arr[%d] : ",i);
    scanf("%d",&arr[i]);
}
char str[100];
printf("Enter a string : ");
getchar();
fgets(str,100,stdin);
int max = maxArr(arr,n);
printf("Maximum : %d\n",max);
vowStr(str);
return 0;
}