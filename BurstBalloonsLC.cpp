class Solution {
public:
    int rec(vector<int>& nums, vector<vector<int>>& dp, int l, int r)
    {
        if(l > r)
            return 0;
        if(dp[l][r] != -1)
            return dp[l][r];
        int ans = 0;
        for(int i = l; i <= r; i++)
        ans = max(ans,nums[l - 1] * nums[i] * nums[r + 1] + rec(nums, dp, l, i - 1) + rec(nums, dp, i + 1, r));
        return dp[l][r] = ans;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        // int ans = rec(nums, dp, 1, n);
        for(int i = n; i >= 1; i--)
        {
            int best = 0;
            for(int j = 1; j <= n; j++)
            {
                if(i > j)
                continue;
                for(int k = i; k <= j; k++)
                {
                    int ans = nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k - 1] + dp[k + 1][j];
                    best = max(best, ans);
                }
                dp[i][j] = best;
            }
        }
        return dp[1][n];
    }
};
