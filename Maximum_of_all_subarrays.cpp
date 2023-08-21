vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        int temp = k;
        int e = 0;
        multiset<int> s;
        while(e < temp - 1)
        {
            s.insert(arr[e]);
            e++;
        }
        vector<int> vec;
        while(e < n)
        {
            s.insert(arr[e]);
            int ele = *s.rbegin();
            auto it = s.find(arr[e - (temp - 1)]);
            s.erase(it);
            vec.push_back(ele);
            e++;
        }
        return vec;
    }
