map<int, vector<int>> mp;
int dp[1001][1001];
int rec(int i, int j, int N, int M, string& X, string& Y)
{
    if(i >= M)
        return 0;
    int take = 0, notTake = 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    notTake = (j == 0)? rec(i + 1, 0, N, M, X, Y) : 0;
    if(mp.count(Y[i])) // take
    {
        auto next = lower_bound(mp[Y[i]].begin(), mp[Y[i]].end(), j);
        if(next != mp[Y[i]].end()) // can't find any matching character in X, so just return the notTake answer
            take = 1 + rec(i + 1, *next + 1, N, M, X, Y);
    }
    // not Take
    return dp[i][j]= max(take, notTake); // return the max of both the options
}
int maxSubsequenceSubstring(string X, string Y, int N, int M) {
    // code
    mp.clear();
    for(int i = 0; i < N; i++)
        mp[X[i]].push_back(i);
    memset(dp, -1, sizeof(dp));
    return rec(0, 0, N, M, X, Y);
}
