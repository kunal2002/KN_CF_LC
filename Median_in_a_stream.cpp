vector<int> findMedian(vector<int> &arr, int n){
	
	// Write your code here 
	vector<int> order;
	vector<int> ans;
	order.push_back(arr[0]);
	ans.push_back(arr[0]);
	for(int i = 1; i < n; i++)
	{
		int j = 0;
		int m = order.size();
		while(j < m)
		{
			if(order[j] >= arr[i])
				break;
			j++;
		}
		order.insert(order.begin() + j, arr[i]);
		m++;
		if(!(m&1))
		{
			ans.push_back((order[m / 2] + order[m / 2 - 1]) / 2);
		}
		else
			ans.push_back(order[m / 2]);
	}
	return ans;
}
