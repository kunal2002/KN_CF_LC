class Solution {
public:
    bool rec(vector<int>& nums, int target, int i, vector<vector<int>>& dp)
    {
        if(target == 0)
        {
            dp[i][target] = true;
            return true;
        }
        if(i >= nums.size() - 1)
            return target == nums[nums.size() - 1];
        if(dp[i][target] != -1)
            return dp[i][target];
        int h = 0;
        if(target >= nums[i])
            h = rec(nums, target - nums[i], i + 1, dp);
        int l = rec(nums, target, i + 1, dp);
        return dp[i][target] = (h || l);
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum&1)
            return false;
        int target = sum / 2;
        vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, -1));
        int res = rec(nums, target, 0, dp);
        return res;
    }
};
