#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
/*Write a C program to dynamically allocate a 2D integer matrix using
double pointers.
• Initialize the matrix with values.
• Write a function to print the matrix using pointer access.
• Describe how memory is allocated and released.*/
void printArr(int **arr, int row , int col){
for (int i = 0; i < row; i++){    
    for (int j = 0; j < col; j++)
        printf("%d ",*(*(arr + i)+j));
    printf("\n");
}
}
int main(){
int row,col;
printf("Enter number of rows : ");
scanf("%d", &row);
printf("Enter number of columns : ");
scanf("%d", &col);
int **ptr = (int **) malloc(row*sizeof(int *));
if(ptr == NULL){ 
    printf("memory allocation failed");
    return 0;
}
for (int i = 0; i < row; i++)
{
    ptr[i] = (int *) malloc(col*sizeof(int));
    if(ptr[i] == NULL){
      printf("memory allocation failed");
    return 0;
    }
}
for (int i = 0; i < row; i++)
{ 
    printf("Enter values of %dth row : ", i);
    for (int j = 0; j < col; j++)
    {
        scanf("%d",(*(ptr + i)+j));
    }
}
printArr(ptr,row,col);
return 0;
}