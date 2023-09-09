class Solution {
public:
    int mod = 1e9 + 7;
    int countTexts(string str) {
        int n = str.size();
        vector<int> dp(n + 1);
        dp[0] = 1;
        for(int i = 1; i <= n; i++)
        {
            dp[i] = dp[i - 1];
            // we take the number of ways till the prev index and then add more ways taking into
            // consideration based on the previous positions if they are same
            if(i - 2 >= 0 && str[i - 1] == str[i - 2])
                dp[i] = (dp[i]%mod + dp[i - 2]%mod) % mod;
            if(i - 3 >= 0 && str[i - 1] == str[i - 2] && str[i - 1] == str[i - 3])
                dp[i] = (dp[i]%mod + dp[i - 3]%mod) % mod;
            if(str[i - 1] == '7' || str[i - 1] == '9')
            {
                if(i - 4 >= 0 && str[i - 1] == str[i - 2] && str[i - 1] == str[i - 3] && str[i - 1] == str[i - 4])
                dp[i] = (dp[i]%mod + dp[i - 4]%mod) % mod;
            }
            dp[i] %= mod;
        }
        return dp[n];
    }
};
