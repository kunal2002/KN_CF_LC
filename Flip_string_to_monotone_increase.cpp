class Solution {
public: 
    int dp[100001][2];
    int rec(int i, bool mono, string& s)
    {
        if(i == s.size())
            return 0;
        if(dp[i][mono] != -1)
            return dp[i][mono];
        int flip = INT_MAX, notFlip = INT_MAX;
        if(s[i] == '0' && !mono)
        {
            flip = 1 + rec(i + 1, !mono, s);
            notFlip = rec(i + 1, mono, s);
        }
        else if(s[i] == '0' && mono)
            flip = 1 + rec(i + 1, mono, s);
        else if(s[i] == '1' && !mono)
        {
            flip = 1 + rec(i + 1, mono, s);
            notFlip = rec(i + 1, !mono, s);
        }
        else
            notFlip = rec(i + 1, mono, s);
        return dp[i][mono] = min(flip, notFlip);
    }
    int minFlipsMonoIncr(string s) {
        memset(dp, -1, sizeof(dp));
        return rec(0, false, s);
    }
};
