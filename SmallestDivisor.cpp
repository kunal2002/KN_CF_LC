int check(int limit, vector<int>& arr, int mid)
{
	int sum = 0;
	for(int i = 0; i < arr.size(); i++)
		sum += ceil(arr[i]*1.0 / mid*1.0);		
	if(sum <= limit)
		return mid;
	return -1;
}
int smallestDivisor(vector<int>& arr, int limit)
{
	// Write your code here.
	sort(arr.begin(), arr.end());
	int n = arr.size();
	int s = 1, e = arr[n - 1];
	//Binary Search
	int mini = 100000010;
	while(s <= e)
	{
		int sum = 0;
		int mid = (s + e) / 2;
		if(check(limit, arr, mid) != -1)
		{
			mini = min(mini, mid);
			e = mid - 1;
		}
		else
			s = mid + 1;
	}
	return mini;
}
