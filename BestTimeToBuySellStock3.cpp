class Solution {
public:
    int rec(vector<int>& vec, int i, int n, bool buy, int maxTrans, vector<vector<vector<int>>>& dp)
    {
        if(i == n || maxTrans == 0)
            return 0;
        if(dp[i][buy][maxTrans] != -1)
            return dp[i][buy][maxTrans];

        if(buy)
            return dp[i][buy][maxTrans] = max(-vec[i] + rec(vec, i + 1, n, false, maxTrans, dp), rec(vec, i + 1, n, true, maxTrans, dp));

            return dp[i][buy][maxTrans] = max(vec[i] + rec(vec, i + 1, n, true, maxTrans - 1, dp), rec(vec, i + 1, n, false, maxTrans, dp));
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //At most 2 transactions
        vector<vector<vector<int>>> dp(n + 2, vector<vector<int>>(3, vector<int>(3, 0)));
        // int ans = rec(prices, 0, n, true, 2, dp);
        //Tabulation
        //maxtrans condition
        int maxTrans = 2;

        for(int i = n - 1; ~i; i--)
        {
            for(int j = 1; j <= 2; j++)
            {
                dp[i][1][j] = max(-prices[i] + dp[i + 1][0][j], dp[i + 1][1][j]);
                dp[i][0][j] = max(prices[i] + dp[i + 1][1][j - 1], dp[i + 1][0][j]);
            }
        }      
        //0th day pr toh sirf buy kr skte hai no sell and maxTrans 2 are left hence our dp state becoems  
        return dp[0][1][2];
    }
};
