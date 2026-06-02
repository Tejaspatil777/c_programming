#include<iostream>
using namespace std;

long long gcd(long long a, long long b)
{
    while(b !=0)
    {
        long long temp =b;
        b =a %b;
        a =temp;

   }
   return a;
}
int main()
{ long long x,y,z;
    cin>>x>>y;
    cin>>z;
    long long g =gcd(x,y);
    if(z<= (x+y) && z %g ==0)
    {
        cout<<"YES";
    } 
    else{
        cout<<"NO";
    }
    return 0;
}