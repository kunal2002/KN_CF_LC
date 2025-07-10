class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> line;
        if(startTime[0])
            line.push_back(startTime[0]);
        line.push_back(-1);
        int ans = 0;
        for(int i = 1; i < n; i++)
        {
            int diff = startTime[i] - endTime[i - 1];
            if(diff > 0)
            {
                line.push_back(diff);
                line.push_back(-1);
            }
            else
                line.push_back(-1);
        }
        if(eventTime != endTime[n - 1])
            line.push_back(eventTime - endTime[n - 1]);
        int sum = 0, best = 0, sz = line.size();
        vector<int> suff, pref;
        int maxi = 0;
        for(int i = sz - 1; ~i; i--)
        {
            maxi = max(maxi, line[i]);
            suff.push_back(maxi);
        }
        maxi = 0;
        for(int i = 0; i < sz; i++)
        {
            maxi = max(maxi, line[i]);
            pref.push_back(maxi);
        }
        best = maxi;
        reverse(suff.begin(), suff.end());
        int cnt = 0;
        for(int i = 0; i < sz; i++)
        {
            if(line[i] != -1)
                cnt++;
            if(line[i] == -1)
            {
                if( (i + 2 < sz && suff[i + 2] >= (endTime[i - cnt] - startTime[i - cnt])) || (i - 2 >= 0 && pref[i - 2] >= (endTime[i - cnt] - startTime[i - cnt])))
                    best = max(best, (i - 1 >= 0 ? (line[i - 1] == -1 ? 0 : line[i - 1]) : 0) + (i + 1 < sz ? (line[i + 1] == -1 ? 0 : line[i + 1]) : 0) + (endTime[i - cnt] - startTime[i - cnt]));
                else
                    best = max(best, (i - 1 >= 0 ? line[i - 1] : 0) + (i + 1 < sz ? line[i + 1] : 0));
            }
        }
        return best;
    }
};
