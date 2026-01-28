/*Exercise 2
Edit Distance (DP)
Description
Compute the minimum edits (insert/delete/replace) to convert str1 to
str2.
Exercise
Convert "horse" to "ros" with minimum edits.*/

#include <stdio.h>
#include <string.h>

int min(int a,int b,int c){
    if(a<b && a<c) return a;
    else if(b<c) return b;
    else return c;
}

int editDistance(char s1[], char s2[], int m, int n){

    int dp[m+1][n+1];

    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){

            if(i==0)
                dp[i][j]=j;   // insert all
            else if(j==0)
                dp[i][j]=i;   // delete all

            else if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1];

            else
                dp[i][j]=1 + min(
                                dp[i][j-1],   // insert
                                dp[i-1][j],   // delete
                                dp[i-1][j-1]  // replace
                               );
        }
    }
    return dp[m][n];
}

int main(){

    char s1[]="horse";
    char s2[]="ros";

    printf("Edit Distance = %d\n",
            editDistance(s1,s2,strlen(s1),strlen(s2)));

    return 0;
}
