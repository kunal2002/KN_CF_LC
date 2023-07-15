#include<bits/stdc++.h>
int rec(vector<int>& price, int i, int n, int cnt,vector<vector<int>>& dp)
{
	if(cnt > n || i > n)
		return -1e8;
	if(cnt == n) 
		return 0;
	if(dp[i][cnt] != -1)
		return dp[i][cnt];
	int same = price[i - 1] + rec(price, i, n, cnt + i, dp);
	int notSame = rec(price, i + 1, n, cnt, dp);
	return dp[i][cnt] = max(same, notSame);
}
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
	int ans = rec(price, 1, n, 0, dp);
	return ans;
}
