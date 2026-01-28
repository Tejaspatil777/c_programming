/*Practice Assignment I
Coin Change Problem with Dynamic Programming and
Greedy Algorithm
Problem Description
A software application needs a system to solve the coin change problem
using dynamic programming and greedy algorithms. This case study
outlines a structured approach for developing a solution to the coin
change problem.
This Beginner to Intermediate case study helps you apply your knowledge and skills of Dynamic
Programming & Greedy Algorithm to solve the problems of a real-life scenario.
1
MODULE | DATA STRUCTURE AND ANALYSIS OF ALGORITHM
This material is owned by Tata Consultancy Services Limited. Unauthorized duplication,
reproduction, downloading, or screen capturing is strictly forbidden and may result in legal
action, unless you obtain TCS's written permission. Using our Services does not give you
ownership of any intellectual property rights in our Services or the content you access.
2
Task 1:
1. Dynamic Programming Solution
Implement a dynamic programming solution to the coin change
problem.
2. Greedy Algorithm Solution
Implement a greedy algorithm solution to the coin change problem.
Hints
ü Use functions to implement dynamic programming and greedy
algorithm solutions.
ü Test the system by solving the coin change problem with given coin
denominations and target amount.*/

#include <stdio.h>
#include <limits.h>

#define MAX 50

/* ---------- Utility min ---------- */
int min(int a,int b){
    return (a<b)?a:b;
}

/* ========== DP SOLUTION ========== */
/*
Find minimum coins using Dynamic Programming
*/
int coinChangeDP(int coins[], int n, int amount){

    int dp[amount+1];
    dp[0] = 0;

    for(int i=1;i<=amount;i++)
        dp[i] = INT_MAX;

    for(int i=1;i<=amount;i++){
        for(int j=0;j<n;j++){

            if(coins[j] <= i){
                int res = dp[i - coins[j]];

                if(res != INT_MAX)
                    dp[i] = min(dp[i], res + 1);
            }
        }
    }

    if(dp[amount] == INT_MAX)
        return -1;
    else
        return dp[amount];
}

/* ========== GREEDY SOLUTION ========== */
/*
Always pick largest coin first
*/
int coinChangeGreedy(int coins[], int n, int amount){

    int count = 0;

    for(int i=n-1;i>=0;i--){

        while(amount >= coins[i]){
            amount -= coins[i];
            count++;
        }
    }

    if(amount != 0)
        return -1;

    return count;
}

/* ---------- MAIN ---------- */
int main(){

    int coins[MAX], n, amount, ch, res;

    printf("Enter number of coin types: ");
    scanf("%d",&n);

    printf("Enter coin denominations (ascending order):\n");
    for(int i=0;i<n;i++)
        scanf("%d",&coins[i]);

    printf("Enter target amount: ");
    scanf("%d",&amount);

    while(1){

        printf("\n---- COIN CHANGE MENU ----\n");
        printf("1. Dynamic Programming Solution\n");
        printf("2. Greedy Solution\n");
        printf("3. Exit\n");

        printf("Enter choice: ");
        scanf("%d",&ch);

        switch(ch){

        case 1:
            res = coinChangeDP(coins,n,amount);

            if(res==-1)
                printf("No solution possible\n");
            else
                printf("Minimum coins (DP) = %d\n",res);
            break;

        case 2:
            res = coinChangeGreedy(coins,n,amount);

            if(res==-1)
                printf("No solution possible (Greedy fails)\n");
            else
                printf("Minimum coins (Greedy) = %d\n",res);
            break;

        case 3:
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }
}
