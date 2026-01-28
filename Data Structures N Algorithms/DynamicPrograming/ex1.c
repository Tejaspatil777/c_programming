/*Exercise 1
Fibonacci Sequence with Dynamic Programming
Description
Compute the nth Fibonacci number using memorization to avoid
redundant calculations.
Exercise
Given n = 10, return fib(10) using a DP approach*/

#include <stdio.h>

int dp[100];   // memory array

int fib(int n){

    if(n == 0) return 0;
    if(n == 1) return 1;

    /* If already calculated */
    if(dp[n] != -1)
        return dp[n];

    /* Store result */
    dp[n] = fib(n-1) + fib(n-2);
    return dp[n];
}

int main(){

    int n = 10;

    /* Initialize dp array */
    for(int i=0;i<=n;i++)
        dp[i] = -1;

    printf("Fibonacci(%d) = %d\n", n, fib(n));

    return 0;
}
