class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b)
    {
        return a[1] < b[1];
    }
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), comp);
        vector<int> hey = queries;
        sort(queries.begin(), queries.end());
        vector<int> ans;
        vector<int> time(queries[queries.size() - 1] + x + 1, -1);
        int s = 1, e = 1, l = 0, q = 0, st = 0;
        map<int, int> mp;
        while(e < time.size())
        {
            if(e - s > x)
            {
                while(st < logs.size() && logs[st][1] == s)
                {
                    mp[logs[st][0]]--;
                    if(mp[logs[st][0]] == 0)
                        mp.erase(logs[st][0]);
                    st++;
                }
                s++;
            }
            while(l < logs.size() && e == logs[l][1])
                mp[logs[l++][0]]++;
            if(q < queries.size() && e == queries[q])
            {
                time[e] = n - mp.size();
                q++;
            }
            e++;
        }
        for(int i = 0; i < hey.size(); i++)
            ans.push_back(time[hey[i]]);
        return ans;
    }
};
//Debug Statements
// cout << s << "->" << e << "\n";
// for(auto z : mp)
//     cout << z.first << " " << z.second << "\n";
