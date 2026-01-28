/*Practice Assignment I
Sorting and Searching in a List of Strings
Problem Description
A software application needs a system to manage a collection of strings
using sorting and searching algorithms. This case study outlines a
structured approach for developing a simple system to sort and search
strings in a list.
This Beginner to Intermediate case study helps you apply your knowledge and skills
of Sorting & Searching Algorithms of a real-life scenario.
1
MODULE | DATA STRUCTURE AND ANALYSIS OF ALGORITHM
This material is owned by Tata Consultancy Services Limited. Unauthorized duplication,
reproduction, downloading, or screen capturing is strictly forbidden and may result in legal
action, unless you obtain TCS's written permission. Using our Services does not give you
ownership of any intellectual property rights in our Services or the content you access.
2
Tasks
1. Sorting Algorithms
Implement the following sorting algorithms:
• Selection Sort
• Merge Sort
2. Searching Algorithms
Implement the following searching algorithms:
• Linear Search
• Binary Search
Hints
ü Use functions to implement sorting algorithms.
ü Use functions to implement searching algorithms.
ü Test the system by sorting and searching strings in a list.*/

#include <stdio.h>
#include <string.h>

#define MAX 20
#define LEN 50

/* Display strings */
void display(char arr[][LEN], int n){
    for(int i=0;i<n;i++)
        printf("%s\n",arr[i]);
}

/* ================= SELECTION SORT ================= */
void selectionSort(char arr[][LEN], int n){

    char temp[LEN];

    for(int i=0;i<n-1;i++){
        int min=i;

        for(int j=i+1;j<n;j++){
            if(strcmp(arr[j],arr[min])<0)
                min=j;
        }

        if(min!=i){
            strcpy(temp,arr[i]);
            strcpy(arr[i],arr[min]);
            strcpy(arr[min],temp);
        }
    }
}

/* ================= MERGE SORT ================= */
void merge(char arr[][LEN], int l,int m,int r){

    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;

    char L[n1][LEN],R[n2][LEN];

    for(i=0;i<n1;i++)
        strcpy(L[i],arr[l+i]);

    for(j=0;j<n2;j++)
        strcpy(R[j],arr[m+1+j]);

    i=0; j=0; k=l;

    while(i<n1 && j<n2){
        if(strcmp(L[i],R[j])<=0)
            strcpy(arr[k++],L[i++]);
        else
            strcpy(arr[k++],R[j++]);
    }

    while(i<n1)
        strcpy(arr[k++],L[i++]);

    while(j<n2)
        strcpy(arr[k++],R[j++]);
}

void mergeSort(char arr[][LEN], int l, int r){

    if(l<r){
        int m=(l+r)/2;

        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

/* ================= LINEAR SEARCH ================= */
int linearSearch(char arr[][LEN], int n, char key[]){
    for(int i=0;i<n;i++){
        if(strcmp(arr[i],key)==0)
            return i;
    }
    return -1;
}

/* ================= BINARY SEARCH ================= */
int binarySearch(char arr[][LEN], int n, char key[]){

    int low=0,high=n-1,mid;

    while(low<=high){
        mid=(low+high)/2;

        if(strcmp(arr[mid],key)==0)
            return mid;
        else if(strcmp(arr[mid],key)<0)
            low=mid+1;
        else
            high=mid-1;
    }
    return -1;
}

/* ================= MAIN ================= */
int main(){

    char arr[MAX][LEN];
    int n,ch,pos;
    char key[LEN];

    printf("Enter number of strings: ");
    scanf("%d",&n);

    printf("Enter strings:\n");
    for(int i=0;i<n;i++)
        scanf("%s",arr[i]);

    while(1){

        printf("\n---- MENU ----\n");
        printf("1. Selection Sort\n");
        printf("2. Merge Sort\n");
        printf("3. Linear Search\n");
        printf("4. Binary Search\n");
        printf("5. Display Strings\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d",&ch);

        switch(ch){

        case 1:
            selectionSort(arr,n);
            printf("Sorted using Selection Sort\n");
            break;

        case 2:
            mergeSort(arr,0,n-1);
            printf("Sorted using Merge Sort\n");
            break;

        case 3:
            printf("Enter string to search: ");
            scanf("%s",key);
            pos=linearSearch(arr,n,key);

            if(pos!=-1)
                printf("Found at index %d\n",pos);
            else
                printf("Not found\n");
            break;

        case 4:
            printf("Enter string to search: ");
            scanf("%s",key);

            /* Binary search needs sorted list */
            mergeSort(arr,0,n-1);

            pos=binarySearch(arr,n,key);

            if(pos!=-1)
                printf("Found at index %d\n",pos);
            else
                printf("Not found\n");
            break;

        case 5:
            display(arr,n);
            break;

        case 6:
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }
}
