class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp, go;
        int n = s.size();
        for(auto &c : t)
            mp[c]++;
        go = mp;
        int st = 0, en = 0, best = 1e5 + 7, cnt = go.size();
        int fst = -1, fen = -1;
        string ans = "";
        while(en < n)
        {
            go[s[en]]--;
            if(go[s[en]] == 0 && mp.find(s[en]) != mp.end())
                cnt--;
            while(cnt == 0)
            {
                if(best > (en - st + 1))
                {   
                    best = en - st + 1;
                    fst = st;
                    fen = en;
                }
                go[s[st]]++;
                if(go[s[st]] > 0 && mp.find(s[st]) != mp.end())
                    cnt++;
                st++;
            }
            en++;
        }
        while(st < en && cnt == 0)
        {
            if(best > (en - st + 1))
            {   
                best = en - st + 1;
                fst = st;
                fen = en;
            }
            go[s[st]]++;
            if(go[s[st]] > 0 && mp.find(s[st]) != mp.end())
                cnt++;
            st++;
        }
        if(fst == -1 && fen == -1)
            return "";
        ans = s.substr(fst, (fen - fst + 1));
        return ans;
    }
};
