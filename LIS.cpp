class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        res.push_back(nums[0]);
        for(int i = 1; i < n; i++)
        {
            auto it = lower_bound(res.begin(), res.end(), nums[i]);
            if(it == res.end())
                res.push_back(nums[i]);
            else
                res[it - res.begin()] = nums[i];
        }
        return res.size();
    }
};
