int subarrayWithMaxProduct(vector<int> &arr){
	// Write your code here.
	// we will consider prefix product and suffix product at every point and just contain the maximum
	int pre = 1, suff = 1;
	int n = arr.size();
	int maxi = INT_MIN;
	for(int i = 0; i < n; i++)
	{
		pre = pre * arr[i];
		suff = suff * arr[n - i - 1];
		if(pre == 0)
			pre = 1;
		if(suff == 0)
			suff = 1;
		maxi = max(maxi, max(pre, suff));
	}
	return maxi;
}
