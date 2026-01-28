#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
/*Develop a menu-driven program that allows users to:
1. Check if a number is prime
2. Generate Fibonacci series upto n terms
3. Check if a number is palindrome
4. Exit the program*/
int checkPrime(void);
void fib(void);
void checkPalindrome(void);
int main(){
int x ;
do{ 
    printf("\nMenu ----->\n");
    printf("1. Check if a number is prime\n");
    printf("2. Generate Fibonacci series upto n terms\n");
    printf("3. Check if a number is palindrome\n");
    printf("4. Exit the program\n");
    printf("Enter your choice : ");
    scanf("%d", &x);
    switch (x){ 
    case 1: checkPrime();
    break;
    case 2: fib();
    break;
    case 3: checkPalindrome();
    break;
    case 4: printf("Invalid choice ---->");
    break;
    default:
        break;
    }
}while(x != 4);
return 0;
}
int checkPrime(void){ 
int n;
printf("Enter any number : ");
scanf("%d", &n);
if (n <= 1) {
        printf("%d is not a prime number\n", n);
        return 0;
    }
for( int i = 2 ; i <= n/2 ; i++ ){ 
    if(n % i == 0) { 
        printf("%d is not  a prime number", n);
        return 0;
    }
}
printf("%d is a prime number\n",n);
return 0;
}
void fib(void){
    int n , n1=0 , n2=1;
    unsigned int sum = 0 ;
    printf("Enter value of n : ");
    scanf("%d", &n);
    if(n<=0) {
        printf("No Fibonacci Series ----->");
        return;
    }
    if( n == 1 ) {
        printf("0");
        return;
    }
    printf("%d %d",n1,n2);
    for(int i=3 ; i<=n ; i++){ 
        printf(" %u", sum = n1 + n2);
        n1 = n2 ;
        n2 = sum;
    }
    return;
}
void checkPalindrome(void){
    int n , rev  = 0;
    printf("Enter a number : ");
    scanf("%d", &n);
    int temp = n ;
    while(temp > 0){
        rev = rev * 10 + temp % 10;
        temp/=10;
    }
    if( n == rev) printf("Palindrome number");
    else printf("Not a Palindrome number");
    return;
}


