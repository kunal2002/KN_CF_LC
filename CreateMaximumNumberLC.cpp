class Solution {
public:
    vector<int> maxLen(vector<int>& nums, int k)
    {
        deque<int> st;
        vector<int> ans;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && (nums[i] > st.back()) && (k - (int)st.size() <= (n - i - 1)))
                st.pop_back();
            if(st.size() < k)
                st.push_back(nums[i]);
        }
        while(!st.empty())
        {
            ans.push_back(st.front());
            st.pop_front();
        }
        return ans;
    }
    bool greater(vector<int>& a, vector<int>& b, int i, int j)
    {
        while(i < a.size() || j < b.size())
        {
            if(i >= a.size()) return false;
            else if(j >= b.size()) return true;
            else if(a[i] > b[j]) return true;
            else if(b[j] > a[i]) return false;
            else
                ++i, ++j;
        }
        return true;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans;
        for(int i = 0; i <= k; i++)
        {
            int other = k - i;
            if(nums1.size() < i || nums2.size() < other)
                continue;
            vector<int> num1 = maxLen(nums1, i);
            vector<int> num2 = maxLen(nums2, other);
            int x = 0, y = 0;
            vector<int> res;
            while((x < i) && (y < other))
            {
                if(num1[x] > num2[y])
                {
                    res.push_back(num1[x]);
                    x++;
                }
                else if(num1[x] < num2[y])
                {
                    res.push_back(num2[y]);
                    y++;
                }
                else
                {
                    if(greater(num1, num2, x, y))
                    {
                        res.push_back(num1[x]);
                        x++;
                    }
                    else
                    {
                        res.push_back(num2[y]);
                        y++;
                    }
                }
            }
            while(x < num1.size())
            res.push_back(num1[x++]);
            while(y < num2.size())
            res.push_back(num2[y++]);
            if(ans.size() == 0)
                ans = res;
            else
            {
                int flag = 0;
                for(int i = 0; i < k; i++)
                {
                    if(ans[i] < res[i])
                    {
                        flag = 1;
                        ans.clear();
                        break;
                    } 
                    else if(res[i] < ans[i])
                        break;
                }
                if(flag)
                    ans = res;
            }
        }
        return ans;
    }
};
