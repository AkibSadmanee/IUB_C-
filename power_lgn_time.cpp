/*
Find the value of x^y in lgn time
*/

#include<iostream>
using namespace std;

int power(int x,int n);

int main()
{
    int x = power(5,2);
    cout<<x<<endl;
    return 0;
}


int power(int x, int n){
    if(n == 1) return x;    //base case
    int temp =  power(x, n/2);
    if(n % 2 == 0)return temp * temp; //for even powers
    else return x*temp*temp;    //for odd powers
}

/*
for the solution stated below,
I am using base case if(n == 1) return x (mathematically correct);
instead of base case if(n == 0) return 1 (gives the correct answer);

T(n,k)  = 1 + T(n/2)
        = 2 + T(n/4)
        = k + T(n/2^k)

n/2^k = 1  -> the recursion will stop when T(base case) is hit
lgn = k    -> from the above statement we find k = lgn

T(n.k)  = lgn + T(1)
        = lgn + 0
        = lgn


*/
