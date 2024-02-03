class Solution {
public: 
    string ans = "";
    vector<string> res;
    void rec(int i, int prev, string& s, int cnt)
    {
        if(i == s.size())
            return;
        if(cnt == 3)
        {
            if(s.size() - i > 3)
                return;
            string what = s.substr(i);
            if(what.size() && stoi(what) <= 255)
            {
                if(what.size() > 1 && what[0] == '0')
                    return;
                res.push_back(ans + what);
            }
            return;
        }
        string t = s.substr(prev, (i - prev) + 1);
        ans.push_back(s[i]);
        ans.push_back('.');
        if(t.size() && t.size() <= 3 && stoll(t) <= 255)
        {
            if(t.size() > 1 && t[0] == '0')
            {
                ans.pop_back();
                ans.pop_back();
                return;
            }
            rec(i + 1, i + 1, s, cnt + 1);
        }
        ans.pop_back();
        rec(i + 1, prev, s, cnt);
        ans.pop_back();
    }
    vector<string> restoreIpAddresses(string s) {
        rec(0, 0, s, 0);
        return res;
    }
};
