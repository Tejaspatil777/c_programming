/*Exercise 1
Implement Tim Sort (Hybrid Algorithm)
Description
Tim Sort combines Merge Sort and Insertion Sort for optimized
performance on real-world data.
Exercise
Sort [3, 7, 4, 8, 6, 2, 1, 5] using a simplified version of Tim Sort (use
Insertion Sort for small runs).
Outcome
- Learns hybrid sorting techniques.
- Understands real-world optimizations.*/

#include <stdio.h>

#define RUN 4   // small run size

/* Insertion Sort for small runs */
void insertionSort(int arr[], int left, int right) {

    for(int i = left + 1; i <= right; i++) {

        int temp = arr[i];
        int j = i - 1;

        while(j >= left && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;
    }
}

/* Merge two sorted subarrays */
void merge(int arr[], int l, int m, int r) {

    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for(int i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for(int i = 0; i < n2; i++)
        R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;

    while(i < n1 && j < n2) {

        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while(i < n1)
        arr[k++] = L[i++];

    while(j < n2)
        arr[k++] = R[j++];
}

/* Simplified Tim Sort */
void timSort(int arr[], int n) {

    /* Step 1: Sort small runs using insertion sort */
    for(int i = 0; i < n; i += RUN) {

        int right = (i + RUN - 1 < n - 1) ?
                     i + RUN - 1 : n - 1;

        insertionSort(arr, i, right);
    }

    /* Step 2: Merge runs */
    for(int size = RUN; size < n; size = 2 * size) {

        for(int left = 0; left < n; left += 2 * size) {

            int mid = left + size - 1;
            int right = (left + 2 * size - 1 < n - 1) ?
                          left + 2 * size - 1 : n - 1;

            if(mid < right)
                merge(arr, left, mid, right);
        }
    }
}

int main() {

    int arr[] = {3, 7, 4, 8, 6, 2, 1, 5};
    int n = 8;

    printf("Original Array: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    timSort(arr, n);

    printf("\nSorted Array: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
