#include<stdio.h>
void selectionSort(int arr[],int n){ 
    int temp , minIndex;
for(int i=0 ; i<n-1 ; i++){
    minIndex = i;
    for(int j  = i+1 ; j<n ; j++){ 
        if(arr[j]<arr[minIndex])
            minIndex = j;
    }
    if(minIndex != i){
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
   }
  }
}
int main(){
int arr[100],n ;
printf("Enter size of an array : ");
scanf("%d",&n);
printf("Enter elements of an array -->\n");
for(int i = 0 ; i < n ; i++){ 
    scanf("%d",&arr[i]);
}
selectionSort(arr,n);
printf("After applying Selection Sort -> ");
for(int i = 0 ; i < n ; i++){ 
    printf("%d ",arr[i]);
}
return 0;
}