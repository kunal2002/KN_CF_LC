class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int N = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        int n = N / 2;
        vector<vector<int>> left(n + 1), right(n + 1);
        for(int mask = 0; mask < (1 << n); mask++)
        {
            int l = 0, r = 0, sz = 0;
            for(int i = 0; i < n; i++)
            {
                if(mask&(1<<i))
                {
                    sz++;
                    l += nums[i];
                    r += nums[i + n];
                }
            }
            left[sz].push_back(l);
            right[sz].push_back(r);
        }

        for(int i = 0; i <= n; i++)
            sort(right[i].begin(), right[i].end());
        int res = INT_MAX;
        res = min(abs(sum - 2 * (left[n][0] + right[0][0])), abs(sum - 2 * (left[0][0] + right[n][0])));
        for(int i = 1; i < n; i++)
        {
            for(auto &x : left[i])
            {
                int approxB = (sum - 2 * x) / 2, rsz = n - i;
                auto &vec = right[rsz];
                auto it = lower_bound(vec.begin(), vec.end(), approxB);
                if(it != vec.end())
                    res = min(res, abs(sum - 2 * (x + *it)));
                if(it != vec.begin())
                {
                    it--;
                    res = min(res, abs(sum - 2 * (x + *it)));
                }
            }
        }
        return res;
    }
};
