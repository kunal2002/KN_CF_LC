// User function Template for C++

class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        int dp[n + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(j >= i)
                    dp[i][j] = max(price[i - 1] + dp[i][j - i], dp[i - 1][j]);
                else 
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][n];
    }
};
