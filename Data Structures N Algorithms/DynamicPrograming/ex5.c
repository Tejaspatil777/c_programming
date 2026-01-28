/*Exercise 1
Traveling Salesman Problem (TSP with DP)
Description
Find the shortest route visiting all cities exactly once (DP + Bitmasking).
Exercise
Given a distance matrix [[0, 10, 15, 20], [10, 0, 35, 25], [15, 35, 0, 30], [20,
25, 30, 0]], solve TSP.
Outcome
- Solves NP-hard problems with DP + bitmasking.
- Time complexity: O(n²·2ⁿ).*/

#include <stdio.h>
#include <limits.h>

#define N 4

int dist[N][N] = {
    {0,10,15,20},
    {10,0,35,25},
    {15,35,0,30},
    {20,25,30,0}
};

int dp[1<<N][N];

/* Min function */
int min(int a,int b){
    return (a<b)?a:b;
}

/* TSP recursive DP */
int tsp(int mask, int pos){

    /* All cities visited */
    if(mask == (1<<N)-1)
        return dist[pos][0];

    /* Already computed */
    if(dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INT_MAX;

    for(int city=0; city<N; city++){

        /* If not visited */
        if((mask & (1<<city)) == 0){

            int newAns =
                dist[pos][city] +
                tsp(mask | (1<<city), city);

            ans = min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;
}

int main(){

    /* Initialize DP */
    for(int i=0;i<(1<<N);i++)
        for(int j=0;j<N;j++)
            dp[i][j] = -1;

    int result = tsp(1,0); // start from city 0

    printf("Minimum travelling cost = %d\n", result);

    return 0;
}
