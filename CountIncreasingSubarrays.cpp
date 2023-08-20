int func(int arr[], int n)
    {
        int len = 1;
        int ans = 0;
        for(int i = 0; i < n - 1; i++)
        {
            if(arr[i + 1] > arr[i])
                len++;
            else
            {
                ans += ((len) * (len - 1)) / 2;
                len = 1;
            }
        }
        if(len > 1)
            ans += ((len) * (len - 1)) / 2;
        return ans;
    }
	int countIncreasing(int arr[], int n) {
	    // code here
	    int ans = func(arr, n);
	    return ans;
	}
