class Solution {
public:
    //i -> n, j -> m
    // i -> p, j -> s
    int dp[21][21];
    bool rec(int i, int j, string& s, string& p, int n, int m)
    {
        if(i >= n && j >= m)
            return true;
        if(i >= n)
            return false;
        if(dp[i][j] != -1)
            return dp[i][j];
        bool dot = false, star = false, match = false;
        match = (j < m && (s[j] == p[i] || p[i] == '.'));
        //either don't use star ("") or use star but only if s[j] == p[i] 
        if(i + 1 < n && p[i + 1] == '*')
            star = (rec(i + 2, j, s, p, n, m) || (match && rec(i, j + 1, s, p, n, m)));
        if(match)
            dot = rec(i + 1, j + 1, s, p, n, m);
        return dp[i][j] = (dot || star);
    }
    bool isMatch(string s, string p) {
        int n = p.size(), m = s.size();
        memset(dp, -1, sizeof(dp));
        return rec(0, 0, s, p, n, m);
    }
};
