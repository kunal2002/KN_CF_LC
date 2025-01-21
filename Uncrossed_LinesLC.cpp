class Solution {
public:
    // int dp[501][501];
    // int rec(int i, int j, vector<int>& nums1, vector<int>& nums2)
    // {
    //     if(i >= nums1.size() || j >= nums2.size())
    //         return 0;
    //     if(dp[i][j] != -1)
    //         return dp[i][j];
    //     int ans = 0;
    //     if(nums1[i] == nums2[j])
    //         ans = 1 + rec(i + 1, j + 1, nums1, nums2);
    //     return dp[i][j] = max({ans, rec(i + 1, j, nums1, nums2), rec(i, j + 1, nums1, nums2)});
    // }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = m - 1; j >= 0; j--)
            {
                if(nums1[i] == nums2[j])
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                dp[i][j] = max({dp[i][j], dp[i + 1][j], dp[i][j + 1]});
            }
        }
        return dp[0][0];
    }
};
