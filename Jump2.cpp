class Solution {
public:
    int jump(vector<int>& nums) {
        int s = 0, e = 0;
        int n = nums.size();
        int ans = 0;
        while(e < n - 1)
        {
            int farthest = 0;
            for(int i = s; i <= e; i++)
            {
                farthest = max(farthest, i + nums[i]);
            }
            s = e + 1;
            e = farthest;
            ans++;
        }
        return ans;
    }
};
