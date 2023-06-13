void func(vector<int>& sub, int i, int sum, vector<int>& ans)
    {
        if(i == sub.size())
        {
            ans.push_back(sum);
            return;
        }
        func(sub, i + 1,sum + sub[i], ans);
        func(sub, i + 1, sum, ans);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        func(arr, 0, 0, ans);
        return ans;
    }
