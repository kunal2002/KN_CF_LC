class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if(target == 0) 
            return 1;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        int n = nums.size();
        for(int i = 1; i <= target; i++)
        {
            long long ans = 0;
            for(int j = 0; j < n; j++)
            {
                if(i - nums[j] >= 0)
                    ans += dp[i - nums[j]];
            }
            dp[i] = ans;
        }
        return dp[target];
    }
};
