class Solution {
public:
    float log5(int a, int b)
    {
        float ans = log2(a) / log2(b);
        return ans;
    }
    bool check(string& ans)
    {
        if(ans.size() == 0)
            return false;
        int num = stoi(ans, 0, 2);
        if(!num || ans[0] == '0')
            return false;
        if(ceil(log5(num, 5)) == log5(num, 5))
            return true;
        return false;
    }
    int rec(int i, string& s, string ans)
    {
        if(i == s.size())
        {
            if(check(ans))
                return 0;
            return 1e5;
        }
        int part = 1e5, notPart = 1e5;
        ans.push_back(s[i]);
        if(check(ans))
            part = 1 + rec(i + 1, s, "");
        notPart = rec(i + 1, s, ans);
        ans.pop_back();
        return min(part, notPart);
    }
    int minimumBeautifulSubstrings(string s) {
        int ans = rec(0, s, "");
        if(ans >= 1e5)
            return -1;
        return ans + 1;
    }
};
