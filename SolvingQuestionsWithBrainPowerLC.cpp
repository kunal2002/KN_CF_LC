class Solution {
public:
    // long long dp[100001];
    // long long rec(int i, vector<vector<int>>& questions)
    // {
    //     if(i >= questions.size())
    //         return 0;
    //     if(dp[i] != -1)
    //         return dp[i];
    //     long long take = questions[i][0] + rec(i + questions[i][1] + 1, questions);
    //     long long notTake = rec(i + 1, questions);
    //     return dp[i] = max(take, notTake);
    // }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, 0ll);
        for(int i = n - 1; i >= 0; i--)
        {
            if(i + questions[i][1] + 1 < n)
                dp[i] = questions[i][0] + dp[i + questions[i][1] + 1];
            else
                dp[i] = max(dp[i], (long long)questions[i][0]);
            dp[i] = max(dp[i], dp[i + 1]);
        }
        return dp[0];
    }
};
