#pragma GCC optimize("O3", "unroll-loops")
int mod = 1e9 + 7;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<long long> dp(n, -1);
        stack<int> st;
        long long ans = 0;
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && arr[i] <= arr[st.top()])
                st.pop();
            if(!st.empty())
            {
                int last = st.top();
                dp[i] = dp[last] + arr[i] * (i - last);
            }
            else
                dp[i] = arr[i] * (i + 1);
            st.push(i);
            ans = (ans + dp[i]) % mod;
        }
        return ans;
    }
};
