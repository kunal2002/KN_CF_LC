class Solution {
public:
    int dp[1001][1001];
    int rec(int l, int r, string& s)
    {
        if(l >= s.length() || r < 0)
            return 0;
        if(dp[l][r] != -1)
            return dp[l][r];
        int ans = 0;
        if(s[l] == s[r])    
            ans = 1 + rec(l + 1, r - 1, s);
        else 
            ans = max(rec(l + 1, r, s), rec(l, r - 1, s));
        return dp[l][r] = ans;
    }
    int longestPalindromeSubseq(string s) {
        memset(dp, -1, sizeof(dp));
        return rec(0, s.length() - 1, s);
    }
};
