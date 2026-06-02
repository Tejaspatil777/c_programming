#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct command{
    char com;
    int step;
};
int main(){
int row = 2,col = 2,flag = 1;
struct command C;
do{
  int p1 , p2;
  p1 = row ;
  p2 = col ;
  printf("Enter Commands :");
  scanf(" %c %d", &C.com,&C.step);
  if((C.step>=1 && C.step<=4) && ((C.com == 'U')||(C.com =='D')||(C.com =='L')||(C.com =='R'))){
    if(C.com == 'U') {
     for (int i = 1; i <= C.step; i++) --p1;
    }
    else if (C.com == 'D'){
     for (int i = 1; i <= C.step; i++) ++p1;
    }
    else if (C.com == 'L') {
        for (int i = 1; i <= C.step; i++) --p2;
    }
    else {for (int i = 1; i <= C.step; i++) ++p2;}
    if((p1<0 || p1>4) || (p2<0 || p2>4)) {
        printf("Invalid Positon : (%d,%d) <----- Command Skipped", p1,p2);
        goto error;
    }
    row = p1;
    col = p2;
    printf("Current Position ----> (%d,%d)", row,col);
  }
  error :
  printf("\nEnter 1 to continue and 0 to exit : ");
  scanf("%d",&flag);
}while(flag);
printf("Final Positon ----> (%d,%d)",row,col);
return 0;
}