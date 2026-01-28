/*Exercise 2
Coin Change (Greedy Approach)
Description
Find the minimum number of coins needed to make change using
a greedy algorithm.
Exercise
Given coins [1, 5, 10] and amount = 28, return the coin count.*/

#include <stdio.h>

int main(){

    int coins[] = {10, 5, 1};   // Descending order
    int n = 3;

    int amount = 28;
    int count = 0;

    printf("Coins used: ");

    for(int i = 0; i < n; i++){

        while(amount >= coins[i]){
            amount -= coins[i];
            printf("%d ", coins[i]);
            count++;
        }
    }

    printf("\nTotal coins = %d\n", count);

    return 0;
}
