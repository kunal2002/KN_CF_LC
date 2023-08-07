#include<bits/stdc++.h>
using namespace std;
const int mod = 9;
int sumofdig(long long n)
{
    int sum = 0;
    while(n != 0)
    {
        int dig = n % 10;
        n /= 10;
        sum += dig;
    }
    return sum;
}
long long powr(long long a, long long b)
{
    long long res = 1;
    while(b)
    {
        if(b&1)
            res = res * a;
        res %= mod;
        a = a * a;
        a %= mod;
        b = b >> 1;
    }
    return res;
}
int solve(long long A, long long N){
    int prod = powr(A, N);
    while(prod >= 10)
    {
        int temp = sumofdig(prod);
        prod = temp;
    }
    if(!prod)
        return 9;
    return prod;
}
