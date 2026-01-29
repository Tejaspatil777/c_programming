/*Practice Assignment II
Product Price Management System with Sorting &
Searching Algorithms
Problem Description
A retail store needs a system to manage product prices using sorting and
searching algorithms. This case study outlines a structured approach for
developing a simple Product Price Management System.
This Intermediate to Advanced case study helps you apply your knowledge and skills
of Sorting & Searching Algorithms to solve the problems of a real-life scenario.
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
ü Test the system by sorting and searching product prices*/
#include <stdio.h>
#include <string.h>

#define MAX 50
#define LEN 30

struct Product{
    char name[LEN];
    float price;
};

/* Display products */
void display(struct Product p[], int n){
    printf("\nProduct List:\n");
    for(int i=0;i<n;i++)
        printf("%s  -> %.2f\n", p[i].name, p[i].price);
}

/* ============ SELECTION SORT (By Price) ============ */
void selectionSort(struct Product p[], int n){

    struct Product temp;

    for(int i=0;i<n-1;i++){
        int min=i;

        for(int j=i+1;j<n;j++){
            if(p[j].price < p[min].price)
                min=j;
        }

        if(min!=i){
            temp = p[i];
            p[i] = p[min];
            p[min] = temp;
        }
    }
}

/* ============ MERGE SORT (By Price) ============ */
void merge(struct Product p[], int l,int m,int r){

    int n1=m-l+1;
    int n2=r-m;

    struct Product L[n1], R[n2];

    for(int i=0;i<n1;i++)
        L[i]=p[l+i];

    for(int j=0;j<n2;j++)
        R[j]=p[m+1+j];

    int i=0,j=0,k=l;

    while(i<n1 && j<n2){
        if(L[i].price <= R[j].price)
            p[k++] = L[i++];
        else
            p[k++] = R[j++];
    }

    while(i<n1)
        p[k++] = L[i++];

    while(j<n2)
        p[k++] = R[j++];
}

void mergeSort(struct Product p[], int l, int r){

    if(l<r){
        int m=(l+r)/2;

        mergeSort(p,l,m);
        mergeSort(p,m+1,r);
        merge(p,l,m,r);
    }
}

/* ============ LINEAR SEARCH (By Name) ============ */
int linearSearch(struct Product p[], int n, char key[]){
    for(int i=0;i<n;i++){
        if(strcmp(p[i].name,key)==0)
            return i;
    }
    return -1;
}

/* ============ BINARY SEARCH (By Price) ============ */
int binarySearch(struct Product p[], int n, float key){

    int low=0,high=n-1,mid;

    while(low<=high){

        mid=(low+high)/2;

        if(p[mid].price == key)
            return mid;
        else if(p[mid].price < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

/* ================= MAIN ================= */
int main(){

    struct Product p[MAX];
    int n,ch,pos;
    char nameKey[LEN];
    float priceKey;

    printf("Enter number of products: ");
    scanf("%d",&n);

    printf("\nEnter product details:\n");
    for(int i=0;i<n;i++){
        printf("Product %d name: ",i+1);
        scanf("%s",p[i].name);

        printf("Product %d price: ",i+1);
        scanf("%f",&p[i].price);
    }

    while(1){

        printf("\n---- PRODUCT MENU ----\n");
        printf("1. Selection Sort (By Price)\n");
        printf("2. Merge Sort (By Price)\n");
        printf("3. Search Product by Name\n");
        printf("4. Search Product by Price\n");
        printf("5. Display Products\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d",&ch);

        switch(ch){

        case 1:
            selectionSort(p,n);
            printf("Sorted using Selection Sort\n");
            break;

        case 2:
            mergeSort(p,0,n-1);
            printf("Sorted using Merge Sort\n");
            break;

        case 3:
            printf("Enter product name: ");
            scanf("%s",nameKey);

            pos = linearSearch(p,n,nameKey);

            if(pos!=-1)
                printf("Found: %s -> %.2f\n",
                        p[pos].name,p[pos].price);
            else
                printf("Product not found\n");
            break;

        case 4:
            printf("Enter price to search: ");
            scanf("%f",&priceKey);

            /* Binary search needs sorted list */
            mergeSort(p,0,n-1);

            pos = binarySearch(p,n,priceKey);

            if(pos!=-1)
                printf("Found: %s -> %.2f\n",
                        p[pos].name,p[pos].price);
            else
                printf("Price not found\n");
            break;

        case 5:
            display(p,n);
            break;

        case 6:
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }
}