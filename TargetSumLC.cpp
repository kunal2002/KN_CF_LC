class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum < target)    
            return 0;
        if((sum + target)&1 || (sum + target) < 0)
            return 0;
        int dp[n + 1][sum + 1];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= sum; j++)
            {
                if(i == 0) // no element chosen yet
                    dp[i][j] = 0;
                if(j == 0) // sum is 0 which can be made from every element
                    dp[i][j] = 1;
            }
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j <= sum; j++)
            {
                if(j >= nums[i - 1])
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        int neededSum = (sum + target) / 2;
        return dp[n][neededSum];
    }
};
