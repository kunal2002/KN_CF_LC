class Solution {

  public:
    int minDifference(vector<int>& arr) {
        // Your code goes here
        int n = arr.size(), sum = 0;
        for(auto &x : arr)  
            sum += x;
        bool dp[n + 1][sum + 1];
        memset(dp, false, sizeof(dp));
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= sum; j++)
            {
                if(i == 0) // no element chosen
                    dp[i][j] = false;
                if(j == 0) // sum hi 0 hai
                    dp[i][j] = true;
            }
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= sum; j++)
            {
                if(j >= arr[i - 1])
                    dp[i][j] = (dp[i - 1][j - arr[i - 1]] || dp[i - 1][j]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        vector<int> ans;
        for(int i = 0; i <= sum; i++)
        {
            if(dp[n][i] == true)
                ans.push_back(i);
        }
        int sz = ans.size();
        return abs(sum - 2 * ans[sz / 2]);
    }
};
