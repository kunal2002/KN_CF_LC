class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long prefix = 0, suffix = 0;
        // suffix for row 0
        // prefix for row 1
        int n = grid[0].size();
        for(auto x : grid[0])
            suffix += x;
        long long pre = 0, suff = 0;
        for(int i = 0; i < n; i++)
        {
            suffix -= grid[0][i];
            if(i > 0)
                prefix += grid[1][i - 1];
            if(suffix <= prefix)
                return min(max(pre, prefix), max(suff, suffix));
            suff = suffix;
            pre = prefix;
        }
        return prefix;
    }
};
