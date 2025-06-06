class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<char> suff(n);
        suff[n - 1] = s[n - 1];
        for(int i = n - 2; ~i; i--)
            suff[i] = min(suff[i + 1], s[i]);
        string ans = "", t = "";
        int i = 0;
        while(i < n)
        {
            t.push_back(s[i]);
            char minChar = (i + 1 < n ? suff[i + 1] : s[i]);
            while(!t.empty() && t.back() <= minChar)
            {
                ans += t.back();
                t.pop_back();
            }
            i++;
        }
        while(!t.empty())
        {
            ans += t.back();
            t.pop_back();
        }
        return ans;
    }
};
