int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	int totSum = accumulate(arr.begin(), arr.end(), 0);
	vector<vector<bool>> dp(n + 1, vector<bool>(totSum + 1, false));
	for(int i = 0; i < n; i++)
		dp[i][0] = true;
	int target = totSum;
	//if we are at the last element and that equals our needed element , then target is achievable
	if(arr[0] <= target)
		dp[0][arr[0]] = true;
	for(int i = 1; i < n; i++)
	{
		for(int tar = 1; tar <= target; tar++)
		{
			bool notTake = dp[i - 1][tar];
			bool Take = false;
			if(tar - arr[i] >= 0)
				Take = dp[i - 1][tar - arr[i]];
			dp[i][tar] = (notTake || Take);
		}
	}
	//Checking the tabulation matrix
	int ans = 1e9;
	//target / 2 because after target / 2 , the two subset sum pairs will start repeating
	// iterating over all possible targets and calculating it's counter subset sum
	// s1 = i
	// s2 = totalSum - i;
	// absolute difference = s2 - s1
	for(int i = 0; i <= target / 2; i++)
	{
		if(dp[n - 1][i])
			ans = min(ans, abs((target - i) - i));
	}
	return ans;
}
