int dp[50004];
class Solution {
public:
    int rec(int i, vector<int>& startTime, vector<int>& endTime, vector<int>& profit)
    {
        if(i == profit.size())
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int ind = lower_bound(startTime.begin(), startTime.end(), endTime[i]) - startTime.begin();
        int take = 0, notTake = 0;
        take = profit[i] + rec(ind, startTime, endTime, profit);
        notTake = rec(i + 1, startTime, endTime, profit);
        return dp[i] = max(take, notTake);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        set<pair<int,pair<int,int>>> vec;
        for(int i = 0; i < n; i++)
            vec.insert({startTime[i], {endTime[i], profit[i]}});
        int i = 0;
        for(auto x: vec)
        {
            startTime[i] = x.first;
            endTime[i] = x.second.first;
            profit[i++] = x.second.second;
        }
        memset(dp, -1, sizeof(dp));
        return rec(0, startTime, endTime, profit);
    }   
};
