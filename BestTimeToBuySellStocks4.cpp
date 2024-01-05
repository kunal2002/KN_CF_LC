class Solution {
public:
    int dp[1000][2][1000];
    int rec(int i, vector<int>& prices, bool buy, int k)
    {
        if(i == prices.size())
            return 0;
        if(k == 0)
            return 0;
        if(dp[i][buy][k] != -1)
            return dp[i][buy][k];
        int buying = 0, selling = 0;
        //Can Buy   
        if(buy)
        {
            buying = -prices[i] + rec(i + 1, prices, !buy, k - 1);
            buying = max(buying, rec(i + 1, prices, buy, k));
        }
        else
        {
            selling = +prices[i] + rec(i + 1, prices, !buy, k - 1);
            selling = max(selling, rec(i + 1, prices, buy, k));
        }
        return dp[i][buy][k] = max(buying, selling);

    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return rec(0, prices, true, 2 * k);
    }
};
