class Solution {
public:
    int rec(int i, vector<vector<int>>& events, int k, vector<vector<int>>& dp)
    {
        if(k == 0 || i >= events.size())
            return 0;
        if(dp[i][k] != -1)
            return dp[i][k];
        int take = 0, notTake = 0;
        // if(events[i][0] > r || events[i][1] < l) //curr_start > prev_end || curr_end < prev_start
        //     take = events[i][2] + rec(i + 1, min(l, events[i][0]), max(r, events[i][1]), events, k - 1, dp);

        int next = upper_bound(events.begin(), events.end(), events[i][1],
            [](int val, const vector<int>& event) {
                return val < event[0]; // find first event where start > current end
            }) - events.begin();
        take = events[i][2] + rec(next, events, k - 1, dp);
        notTake = rec(i + 1, events, k, dp);
        return dp[i][k] = max(take, notTake);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        int l = INT_MAX, r = INT_MIN; 
        sort(events.begin(), events.end());
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return rec(0, events, k, dp);
    }
};
