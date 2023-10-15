int mod = 1e9 + 7;
const int p = 501;
const int maxi = 501;
class Solution {
public:
    int dp[p][maxi];
    int rec(int i, int steps, int arrLen)
    {
        if(steps == 0)
        {
            if(i == 0)
                return dp[i][steps] = 1;
            return dp[i][steps] = 0;
        }
        if(dp[i][steps] != -1)
            return dp[i][steps];
        int ans = 0;
        for(int j = -1; j <= 1; j++)
        {
            int next = i + j; // three possible moves -1, 0, 1
            if(next >= steps) // wont be able to reach back to 0 if this is the case
                continue;
            if(next >= 0 && next < arrLen)
            {
                ans += (rec(next, steps - 1, arrLen) % mod);
                ans %= mod;
            }
        }
        return dp[i][steps] = ans;
    }
    int numWays(int steps, int arrLen) {
        memset(dp, -1, sizeof(dp));
        int ans = rec(0, steps, arrLen);
        return ans;
    }
};
