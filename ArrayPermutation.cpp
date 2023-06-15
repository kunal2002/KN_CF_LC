class Solution {
public:
        void func(vector<int>& sub, int ind, map<int,bool>& mp,vector<int>& ans, vector<vector<int>>& res)
    {
        if(ind == sub.size())
        {
            res.push_back(ans);
            return;
        }
        for(int i = 0; i < sub.size(); i++)
        {
            if(!mp[sub[i]])
            {
                ans.push_back(sub[i]);
                mp[sub[i]] = true;
                func(sub, ind + 1, mp, ans, res);
                mp[sub[i]] = false;
                ans.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> res;
        map<int,bool> mp;
        func(nums, 0, mp, ans, res);
        return res;
    }
};
