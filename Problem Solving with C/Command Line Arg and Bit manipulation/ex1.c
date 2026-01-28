#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(int argc,char *argv[]){
int alpha = 0, num = 0;
char temp[30];
for (int i = 1; i < argc; i++){
    strcpy(temp,argv[i]);
    for (unsigned int i = 0; i < strlen(temp); i++){
        if(isalpha(temp[i])) alpha++;
        else if(isdigit(temp[i])) num++;
        else continue;
    }
}
printf("Number of characters : %d\n",alpha);
printf("Number of digits : %d",num);
return 0;
}