class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> pre(nums.size() + 1, 0);
        int n = nums.size();
        for(int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + nums[i]; 
        int ans = 0;
        unordered_map<int, int> mp;
        for(int i = 1; i <= n; i++)
        {
            if(pre[i] == k) ans++;
            if(mp.find(pre[i] - k) != mp.end())
                ans += mp[pre[i] - k];
            mp[pre[i]]++;
        }
        return ans;
    }
};
