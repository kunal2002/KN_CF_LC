class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<int,int>> dp(n);
        int maxi = -1;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                int diff = nums[j] - nums[i];
                if(dp[j].find(diff) != dp[j].end())
                    dp[i][diff] = dp[j][diff] + 1;
                else
                    dp[i][diff] = 2;
                maxi = max(maxi, dp[i][diff]);
            }
        }
        return maxi;
    }
};
