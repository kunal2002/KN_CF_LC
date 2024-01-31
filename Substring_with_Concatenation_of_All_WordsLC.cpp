class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int window = 0, wrd_size = words[0].size();
        unordered_map<char, int> org, dup;
        unordered_map<string, int> mp;
        for(auto x : words)
        {
            window += x.size();
            mp[x]++;
            for(auto c : x)
                org[c]++;
        }   
        // for(auto x: mp)
        //     cout << x.first << " " << x.second << "\n";
        int st = 0, en = 0;
        vector<int> ans;
        string temp = "";
        while(en < s.size() && en < window)
        {
            temp += s[en];
            dup[s[en]]++;
            en++;
        }
        while(en <= s.size())
        {
            if(dup == org)
            {
                int flag = 0;
                unordered_map<string, int> hey;
                int pos = 0;
                while(pos + wrd_size <= temp.size())
                {
                    hey[temp.substr(pos, wrd_size)]++;
                    pos += wrd_size;
                }
                if(mp != hey)
                    flag = 1;
                if(!flag)
                ans.push_back(st);
            }
            temp += s[en];
            dup[s[en]]++;
            en++;
            dup[s[st]]--;
            temp.erase(temp.begin());
            if(dup[s[st]] == 0)
                dup.erase(s[st]);
            st++;
        }
        return ans;
    }
};
