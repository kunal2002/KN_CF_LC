int MOD = 1e9 + 7;
int rec(vector<int>& arr, int k,int i, vector<vector<int>>& dp)
{
	if(k == 0)
		return 1;
	if(i == 0)
		return (arr[i] == k);
	if(dp[i][k] != -1)
		return dp[i][k];
	int notTake = rec(arr, k, i - 1, dp);
	int Take = 0;
	if(arr[i] <= k)
		Take = rec(arr, k - arr[i], i - 1, dp);
	return dp[i][k] = (Take + notTake) % MOD;
}
int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int n = arr.size();
	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
	// int ans = rec(arr, k, n - 1, dp);
	for(int i = 0; i < n; i++)
		dp[i][0] = 1;
	if(arr[0] <= k)
		dp[0][arr[0]] = 1;
	for(int i = 1; i < n; i++)
	{
		for(int tar = 0; tar <= k; tar++)
		{
			int notTake = dp[i - 1][tar];
			int Take = 0;
			if(arr[i] <= tar)
				Take = dp[i - 1][tar - arr[i]];
			dp[i][tar] = (Take + notTake) % MOD;
		}
	}
	return dp[n - 1][k];
}
