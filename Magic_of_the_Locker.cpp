#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long powr(long long a, long long b)
{
    long long res = 1;
    if(b == 0)
        return 1;
    while(b)
    {
        if((b&1))
            res = res * a;
        res %= mod;
        a = a * a;
        a %= mod;
        b = b >> 1;
    }
    return res;
}
int locker(int n){
    int ans = 0;
    if(n < 2)
        ans = n;
    else
    {
        int cnt = n / 3;
        int rem = n % 3;
        if(rem == 1)
        {
            ans = (powr(3, cnt - 1) * 4) % mod;
        }
        else if(rem == 2)
        {
            ans = (powr(3, cnt) * 2) % mod;
        }
        else
        {
            ans = powr(3, cnt);
        }
    }
    return ans;
}
