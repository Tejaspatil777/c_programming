/*Linear Search
Description
Linear Search checks each element in a list sequentially until
the target is found.
Exercise
Search for the number 7 in the array [4, 2, 7, 1, 9] and return
its index.
Outcome
- Learns sequential search logic.
- Understands time complexity (O(n)).*/
#include <stdio.h>

int main() {

    int arr[] = {4, 2, 7, 1, 9};
    int n = 5;
    int key = 7;
    int found = -1;

    for(int i = 0; i < n; i++) {

        if(arr[i] == key) {
            found = i;
            break;
        }
    }

    if(found != -1)
        printf("Element %d found at index %d\n", key, found);
    else
        printf("Element not found\n");

    return 0;
}
