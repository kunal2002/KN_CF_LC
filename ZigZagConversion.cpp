class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if(numRows == 1)
            return s;
        int cnt = 1;
        int diff = 1;
        vector<string> vec(numRows + 1, "");
        for(int i = 0; i < n; i++)
        {
            if(cnt == numRows)
                diff = -1;
            else if(cnt == 1)
                diff = 1;
            vec[cnt].push_back(s[i]);
            cnt += diff;
        }
        string ans = "";
        for(auto x: vec)
            ans += x;
        return ans;
    }
};
