#include <bits/stdc++.h> 
int rec(vector<int>& nums, int i, bool prev, int n, vector<vector<int>>& dp)
{
    if(i >= n)
        return 0;
    if(dp[i][prev] != -1)
        return dp[i][prev];
    int take = -1;
    if(!prev)
        take = nums[i] + rec(nums, i + 1, true, n, dp);
    int notTake = rec(nums, i + 1, false, n, dp);
    int ans = max(take, notTake);
    return dp[i][prev] = ans;
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    if(n == 1)
        return nums[0];
    vector<vector<int>> dp(n + 2, vector<int>(2, -1));
    // int ans = rec(nums, 0, false, n, dp);
    //dp[n][0] = did not take nth element
    dp[n][0] = 0;
    dp[n][1] = 0;
    for(int i = n - 1; ~i; i--)
    {
        dp[i][0] = max(dp[i + 1][1], dp[i + 1][0]);
        dp[i][1] = nums[i] + dp[i + 1][0];
    }
    return max(dp[0][0], dp[0][1]);
}
