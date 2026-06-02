// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countWays(char *str){
    int n = strlen(str);
    if(n==0 || str[0]=='0') return 0;
    int *ways = (int *)malloc((n + 1) * sizeof(int));
    ways[0] = 1;
    ways[1] = 1;
    for(int i = 2 ; i <= n; i++ ) ways[i] = 0;
    for(int i = 0 ; i <= n ; i++ ){
        if(str[i-1] != '0'){
            ways[i]+=ways[i-1];
        }
        int twoDigits = (str[i-2] - '0') * 10 + (str[i-1] - '0');
        if(twoDigits >= 10 && twoDigits <= 26){
            ways[i]+=ways[i-2];
        }
    }
    int result = ways[n];
    free(ways);
    return result;
}

int main() {
    char str[10];
    if(scanf("%s", str)==1){
        printf("%d", countWays(str));
    }
    return 0;
}