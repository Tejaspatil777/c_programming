#include <stdio.h>

struct Job{
    char id;
    int deadline;
    int profit;
};

/* Sort jobs by profit */
void sort(struct Job j[], int n){

    struct Job temp;

    for(int i=0;i<n-1;i++)
        for(int k=i+1;k<n;k++)
            if(j[i].profit < j[k].profit){
                temp=j[i];
                j[i]=j[k];
                j[k]=temp;
            }
}

void greedyJob(struct Job j[], int n){

    sort(j,n);

    int slot[10]={0};
    char result[10];

    int totalProfit=0;

    for(int i=0;i<n;i++){

        for(int d=j[i].deadline; d>0; d--){

            if(slot[d]==0){
                slot[d]=1;
                result[d]=j[i].id;
                totalProfit += j[i].profit;
                break;
            }
        }
    }

    printf("\nGreedy Selected Jobs: ");
    for(int i=1;i<=5;i++)
        if(slot[i])
            printf("%c ",result[i]);

    printf("\nTotal Profit = %d\n",totalProfit);
}

int main(){

    struct Job j[]={
        {'A',2,100},
        {'B',1,19},
        {'C',2,27},
        {'D',1,25},
        {'E',3,15}
    };

    greedyJob(j,5);
}
