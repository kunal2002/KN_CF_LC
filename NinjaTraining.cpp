#include<bits/stdc++.h>
int rec(vector<vector<int>> &vec, int i, int j, vector<vector<int>>& dp) {
    if(i == vec.size())
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int what = -1;
    for (int k = 0; k < 3; k++)
    {
        if(k != j)
            what = max(what, vec[i][k] + rec(vec, i + 1, k, dp));
    }
    return dp[i][j] = what;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n + 2, vector<int>(4, 0));
    // int ans = rec(points, 0, 3, dp);
    for(int i = n - 1; ~i; i--)
    {
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                if(k != j)
                    dp[i][j] = max(dp[i][j], points[i][k] + dp[i + 1][k]);
            }
        }
    }
    return max(dp[0][0], max(dp[0][1], dp[0][2]));
}
