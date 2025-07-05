class Solution {
  public:
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int n = arr.size(), sum = 0;
        for(auto &x : arr)
            sum += x;
        int neededSum = (sum + d) / 2;
        if((sum + d)&1 || neededSum > sum)
            return 0;
        int dp[n + 1][sum + 1]; // denotes if elements taken till i can create a sum j
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= sum; j++)
            {
                if(i == 0) // no element chosen yet
                    dp[i][j] = 0;
                if(j == 0) // sum == 0
                    dp[i][j] = 1;
            }
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j <= sum; j++)
            {
                if(j >= arr[i - 1])
                    dp[i][j] = (dp[i - 1][j - arr[i - 1]] + dp[i - 1][j]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        int ans = 0;
        return dp[n][neededSum];
    }
    
};
