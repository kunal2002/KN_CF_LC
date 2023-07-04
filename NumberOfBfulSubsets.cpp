class Solution {
public:
    void subset(vector<int>& nums, int i, int k,unordered_map<int,int>& mp, int& ans)
    {
        if(i == nums.size())
            ans++;
        else
        {   
            if(!mp[nums[i] - k])
            {
                mp[nums[i]]++;
                subset(nums , i + 1, k, mp, ans);
                mp[nums[i]]--;
            }
            subset(nums , i + 1, k, mp, ans);
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        unordered_map<int,int> mp;
        int ans = 0;
        subset(nums, 0, k, mp, ans);
        return ans - 1;
    }
};
