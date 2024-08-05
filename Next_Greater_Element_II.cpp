class Solution {
public:
    vector<int> nge(vector<int>& nums)
    {
        stack<int> st;
        vector<int> nextge(nums.size());
        for(int i = nums.size() - 1; ~i; i--)
        {
            while(!st.empty() && st.top() <= nums[i])
                st.pop();
            if(!st.empty())
                nextge[i] = st.top();
            else
                nextge[i] = -1;
            st.push(nums[i]);
        }
        return nextge;
    }
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> temp(nums);
        for(auto x : temp)
            nums.push_back(x);
        vector<int> nextge = nge(nums);
        int cnt = temp.size();
        while(cnt--)
            nextge.pop_back();
        return nextge;
    }
};
