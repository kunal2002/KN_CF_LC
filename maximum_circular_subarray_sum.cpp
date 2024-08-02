class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int min_sum = 0, glob_min = INT_MAX, max_sum = 0, glob_max = INT_MIN, n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            min_sum = min(min_sum + nums[i], nums[i]);
            glob_min = min(glob_min, min_sum);
            max_sum = max(max_sum + nums[i], nums[i]);
            glob_max = max(glob_max, max_sum);
        }
        if(glob_min == sum)
            return glob_max;
        return max(glob_max, sum - glob_min);        
    }
};
