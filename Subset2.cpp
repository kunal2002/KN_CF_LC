class Solution {
public:
    void func(int ind, vector<int>& nums, vector<vector<int>>& ans,vector<int>& res)
    {
        ans.push_back(res);
        for(int i = ind; i < nums.size(); i++)
        {
            if(i != ind && nums[i] == nums[i - 1])
                continue;
            res.push_back(nums[i]);
            func(i + 1, nums, ans, res);
            res.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        sort(nums.begin(), nums.end());
        func(0, nums, ans, res);
        return ans;
    }
};
