int dp[11][2][11];
class Solution {
public:
    int rec(string& str, int i, int tight, int cnt)
    {
        if(i == str.size()) return cnt;
        if(dp[i][tight][cnt] != -1) return dp[i][tight][cnt];
        int limit = (tight ? str[i] - '0': 9);
        int ans = 0;
        for(int ind = 0; ind <= limit; ind++)
        {
            int new_cnt = cnt + (ind == 1);
            //if tight == 1 and we have again reached the limit of the subsequent digit, then again put a limit to the next digit
            ans += rec(str, i + 1, (tight & (ind == str[i] - '0')), new_cnt);
        }
        return dp[i][tight][cnt] = ans;
    }
    int countDigitOne(int n) {
        memset(dp, -1, sizeof(dp));
        string str = to_string(n);
        return rec(str, 0, 1, 0);
    }
};
