/*Practice Assignment II
Job Scheduling Problem with Dynamic Programming and
Greedy Algorithm
Problem Description
A software application needs a system to schedule jobs to maximize
profit using dynamic programming and greedy algorithms. This case
study outlines a structured approach for developing a solution to the job
scheduling problem.
This Intermediate to Advanced case study helps you apply your knowledge and skills of Dynamic
Programming & Greedy Algorithm to solve the problems of a real-life scenario.
1
MODULE | DATA STRUCTURE AND ANALYSIS OF ALGORITHM
This material is owned by Tata Consultancy Services Limited. Unauthorized duplication,
reproduction, downloading, or screen capturing is strictly forbidden and may result in legal
action, unless you obtain TCS's written permission. Using our Services does not give you
ownership of any intellectual property rights in our Services or the content you access.
2
Tasks
1. Dynamic Programming Solution
Implement a dynamic programming solution to the job scheduling
problem.
2. Greedy Algorithm Solution
Implement a greedy algorithm solution to the job scheduling
problem.
Hints
ü Use functions to implement dynamic programming and greedy
algorithm solutions.
ü Test the system by scheduling jobs to maximize profit.*/

#include <stdio.h>

struct Job{
    int start, finish, profit;
};

/* Find last non-conflicting job */
int findLast(struct Job j[], int i){

    for(int k=i-1;k>=0;k--)
        if(j[k].finish <= j[i].start)
            return k;
    return -1;
}

/* DP solution */
int jobDP(struct Job j[], int n){

    int dp[10];

    dp[0]=j[0].profit;

    for(int i=1;i<n;i++){

        int incl=j[i].profit;
        int l=findLast(j,i);

        if(l!=-1)
            incl += dp[l];

        dp[i]=(incl > dp[i-1])? incl: dp[i-1];
    }

    return dp[n-1];
}

int main(){

    struct Job j[]={
        {1,3,50},
        {3,5,20},
        {6,19,100},
        {2,100,200}
    };

    printf("Max Profit (DP) = %d\n",jobDP(j,4));
}
