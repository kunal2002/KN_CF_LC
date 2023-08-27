class Solution {
public:
    set<vector<int>> ans;
    void rec(vector<int>& nums, int j, vector<int>& res, unordered_map<int, bool>& mp)
    {
        if(j == nums.size())
        {
            ans.insert(res);
            return;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(!mp[i])
            {
                mp[i] = true;
                res.push_back(nums[i]);
                rec(nums, j + 1, res, mp);
                res.pop_back();
                mp[i] = false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, bool> mp;
        vector<int> res;
        rec(nums, 0, res, mp);
        vector<vector<int>> hey;
        for(auto x: ans)
            hey.push_back(x);
        return hey;
    }
};
