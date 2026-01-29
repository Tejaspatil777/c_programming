/*Exercise 1
Binary Search (Iterative)
Description
Binary Search efficiently locates an element in a sorted array by
repeatedly dividing the search interval in half.
Exercise
Search for 8 in the sorted array [1, 3, 5, 7, 8, 9] using Binary Search.
Outcome
- Understands divide-and-conquer search.
- Learns O(log n) time complexity*/

#include <stdio.h>

int main() {

    int arr[] = {1, 3, 5, 7, 8, 9};
    int n = 6;
    int key = 8;

    int low = 0, high = n - 1, mid;
    int found = -1;

    while (low <= high) {

        mid = (low + high) / 2;

        if (arr[mid] == key) {
            found = mid;
            break;
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if (found != -1)
        printf("Element %d found at index %d\n", key, found);
    else
        printf("Element not found\n");

    return 0;
}
