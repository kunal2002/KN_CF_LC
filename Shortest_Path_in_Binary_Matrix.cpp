class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 0 || grid[0][0] != 0 || grid[n - 1][n - 1] != 0)
            return -1;
        queue<pair<int,pair<int,int>>> q;
        q.push({0, {0, 0}});
        grid[0][0] = 1;
        while(!q.empty())
        {
            int dist = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
            if(x == n - 1 && y == n - 1)
                return dist + 1;
            for(int i = -1; i <= 1; i++)
            {
                for(int j = -1; j <= 1; j++)
                {
                    if(x + i >= 0 && x + i < n && y + j >= 0 && y + j < n)
                    {
                        if(grid[x + i][y + j] != 1)
                        {
                            grid[x + i][y + j] = 1;
                            q.push({dist + 1, {x + i, y + j}});
                        }
                    }
                }
            }
        }
        return -1;
    }
};
