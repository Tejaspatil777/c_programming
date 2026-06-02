#include <stdio.h>
#include <stdlib.h>

void checkPossibility(void) {
    int n;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input for array size.\n");
        return;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed for array.\n");
        return;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input detected.\n");
            free(arr);
            return;
        }
    }

    int *possibleLeft  = (int *)malloc(n * sizeof(int));
    int *possibleRight = (int *)malloc(n * sizeof(int));

    if (possibleLeft == NULL || possibleRight == NULL) {
        printf("Memory allocation failed.\n");
        free(arr);
        free(possibleLeft);
        free(possibleRight);
        return;
    }

   
    int isPossible = 1;
    for (int i = 0; i < n; i++) {
        if (arr[i] < i) {
            isPossible = 0;
        }
        possibleLeft[i] = isPossible;
    }

    isPossible = 1;
    for (int i = n - 1; i >= 0; i--) {
        int distanceFromEnd = n - 1 - i;
        if (arr[i] < distanceFromEnd) {
            isPossible = 0;
        }
        possibleRight[i] = isPossible;
    }

 
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (possibleLeft[i] && possibleRight[i]) {
            found = 1;
            break;
        }
    }

    printf("\nResult: %s\n", found ? "Yes" : "No");

  
    free(arr);
    free(possibleLeft);
    free(possibleRight);
}

int main(void) {
    checkPossibility();
    return 0;
}
