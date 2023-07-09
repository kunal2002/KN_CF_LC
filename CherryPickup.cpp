class Solution {
public:
    int dp[52][52][52];
    int rec(vector<vector<int>>& grid, int n, int i, int j, int i1, int cherry)
    {
        int cherries = 0;
        int j1 = i + j - i1;
        if(i >= n || j >= n || i1 >= n || j1 >= n || grid[i][j] == -1 || grid[i1][j1] == -1)
            return -1e8;
        if(dp[i][j][i1] != -1)
            return dp[i][j][i1];
        if(i == i1 && j == j1 && i == n - 1 && j == n - 1)
            return grid[i][j];

        if(i == i1 && j == j1)
            cherries += grid[i][j];
        else
            cherries += grid[i][j] + grid[i1][j1];
        int a = rec(grid, n, i + 1, j, i1, cherry + cherries);
        int b = rec(grid, n, i + 1, j, i1 + 1, cherry + cherries);
        int c = rec(grid, n, i, j + 1, i1, cherry + cherries);
        int d = rec(grid, n, i, j + 1, i1 + 1, cherry + cherries);
        cherries +=  max(max(a,b), max(c, d));
        return dp[i][j][i1] = cherries;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 1)
        {
            if(grid[0][0] == 1)
                return 1;
            else
                return 0;
        }
        memset(dp, -1, sizeof(dp));
        int ans = rec(grid, n, 0, 0, 0, 0);
        if(ans < 0)
            return 0;
        return ans;
    }
};
