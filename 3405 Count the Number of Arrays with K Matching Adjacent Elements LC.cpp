class Solution {
public: 
    int MOD = 1e9 + 7;
    int fastpow(long long a, long long b)
    {
        long long res = 1;
        while(b)
        {
            if(b&1)
                res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res % MOD;
    }
    long long nCr(int n, int r, vector<long long>& fact, vector<long long>& fermatFact)
    {
        return (((fact[n] * fermatFact[n - r]) % MOD) * fermatFact[r]) % MOD;
    }
    int countGoodArrays(int n, int m, int k) {
        vector<long long> fact(n + 1);
        fact[0] = fact[1] = 1;
        for(int i = 2; i <= n; i++)
            fact[i] = (fact[i - 1] * i) % MOD;
        vector<long long> fermatFact(n + 1);
        for(int i = 0; i <= n; i++)
            fermatFact[i] = fastpow(fact[i], MOD - 2);
        long long res = nCr(n - 1, k, fact, fermatFact);
        res = (res * m) % MOD;
        res = (res * fastpow(m - 1, (n - k - 1))) % MOD;
        return res;
    }
};
