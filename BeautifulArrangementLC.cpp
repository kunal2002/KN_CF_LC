class Solution {
public:
    int dp[65536];
    int rec(int ind, int n, int bitmask)
    {
        if(ind > n)
            return 1;
        if(dp[bitmask] != -1)
            return dp[bitmask];
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            if(!(bitmask&(1 << i)) && ((i % ind == 0) || (ind % i == 0)))
            {
                bitmask |= (1 << i);
                ans += rec(ind + 1, n, bitmask);
                bitmask ^= (1 << i);
            }
        }
        return dp[bitmask] = ans;
    }
    int countArrangement(int n) {
        int mask = 0;
        memset(dp, -1, sizeof(dp));
        return rec(1, n, mask);
    }
};
