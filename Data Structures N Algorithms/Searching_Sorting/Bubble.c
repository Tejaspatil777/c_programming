/*Exercise 1
Implement Bubble Sort
Description
Bubble Sort is a simple comparison-based algorithm that
repeatedly swaps adjacent elements if they are in the wrong
order.
Exercise
Given an array [5, 3, 8, 4, 2], sort it in ascending order using
Bubble Sort.
Outcome
- Understands how Bubble Sort works.
- Learns basic array manipulation and swapping.*/

#include <stdio.h>

int main() {

    int arr[50], n, temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    /* Bubble Sort Logic */
    for(int i = 0; i < n-1; i++) {

        for(int j = 0; j < n-i-1; j++) {

            if(arr[j] > arr[j+1]) {

                /* Swap */
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("\nSorted Array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
