class Solution {
public:
    bool palindrome(string t)
    {
        int n = t.size();
        for(int i = 0; i < n / 2; i++)
        {
            if(t[i] != t[n - i - 1])
                return false;
        }
        return true;
    }
    void rec(string str, int ind, vector<string>& res, vector<vector<string>>& ans, string t)
    {
        if(ind == str.size())
        {
            ans.push_back(res);
            return;
        }
        for(int i = ind; i < str.size(); i++)
        {
            t += str[i];
            if(palindrome(t))
            {
                res.push_back(t);
                rec(str, i + 1, res, ans, "");
                res.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> res;
        vector<vector<string>> ans;
        rec(s, 0, res, ans, "");
        return ans;
    }
};
