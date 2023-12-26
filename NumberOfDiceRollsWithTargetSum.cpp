class Solution {
public:
    int mod = 1e9 + 7;
    int rec(int n, int k, int target, vector<vector<int>>& dp)
    {
        if(n == 0 && target == 0)
            return 1;
        if(n == 0 || target < 0)
            return 0;
        if(dp[target][n] != -1)
            return dp[target][n];
        int ans = 0;
        for(int i = k; i >= 1; i--)
        {
            if((n - 1) * k >= (target - i))
                ans = (ans % mod + rec(n - 1, k, target - i, dp) % mod) % mod;
            else 
                break;
        }
        return dp[target][n] = ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        if(n * k < target)
            return 0;
        vector<vector<int>> dp(target + 1, vector<int>(n + 1, -1));
        return rec(n, k, target, dp);
    }
};
