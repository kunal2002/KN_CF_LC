class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        multiset<long> st;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            auto it = st.lower_bound(nums[i] - valueDiff);
            if(it != st.end() && (*it - nums[i]) <= valueDiff)
                return true;
            st.insert(nums[i]);
            if(st.size() >= indexDiff + 1)
                st.erase(st.find(nums[i - indexDiff]));
        }
        return false;
    }
};
