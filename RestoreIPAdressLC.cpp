class Solution {
public: 
    string ans = "";
    vector<string> res;
    void rec(int i, int prev, string& s, int cnt)
    {
        if(i == s.size())
            return;
        // partitions made now last part of the partition will be from this index to last index, check if it is
        // admissible within the rules of IP address formation
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
        //adding the digit, then putting partition with dot
        ans.push_back(s[i]);
        ans.push_back('.');
        //checking if the digits added since last '.' till present index make a viable number less than 255 and without leading zeros or not
        if(t.size() && t.size() <= 3 && stoll(t) <= 255)
        {
            if(t.size() > 1 && t[0] == '0')
            {
                ans.pop_back();
                ans.pop_back();
                return;
            }
            // partitioning at index i
            rec(i + 1, i + 1, s, cnt + 1);
        }
        // removing the partition
        ans.pop_back();
        // adding the next digit after the previous dot without doing partition
        rec(i + 1, prev, s, cnt);
        ans.pop_back();
    }
    vector<string> restoreIpAddresses(string s) {
        rec(0, 0, s, 0);
        return res;
    }
};
