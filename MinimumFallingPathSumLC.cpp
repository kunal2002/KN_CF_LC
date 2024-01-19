class Solution {
public:
    int dp[101][101];
    int rec(int i, int j, vector<vector<int>>& mat)
    {
        if(i == mat.size())
            return 0;
        int ans = 1e6;
        if(dp[i][j] != 100000)
            return dp[i][j];
        if(j == 0)
        ans = min({ans, mat[i][j] + (dp[i + 1][j] != 100000 ? dp[i + 1][j] : rec(i + 1, j, mat)), mat[i][j] + (dp[i + 1][j + 1] != 100000 ? dp[i + 1][j + 1] : rec(i + 1, j + 1, mat))});
        else if(j == (mat[0].size() - 1))
        ans = min({ans, mat[i][j] + (dp[i + 1][j] != 100000 ? dp[i + 1][j] : rec(i + 1, j, mat)), mat[i][j] + (dp[i + 1][j - 1] != 100000 ? dp[i + 1][j - 1] : rec(i + 1, j - 1, mat))});
        else
        {
            for(int k = j - 1; k <= j + 1; k++)
            ans = min(ans, mat[i][j] + (dp[i + 1][k] != 100000 ? dp[i + 1][k] : rec(i + 1, k, mat)));
        }
        return dp[i][j] = ans;
    }
    int minFallingPathSum(vector<vector<int>>& mat) {
        for(int i = 0; i < 101; i++)
        {
            for(int j = 0; j < 101; j++)
            dp[i][j] = 100000;
        }
        int ans = 1e7;
        for(int k = 0; k < mat[0].size(); k++)
        {
            if(k == 0)
            {
                ans = min({ans, mat[0][k] + (dp[1][k] != 100000 ? dp[1][k] : rec(1, k, mat)), mat[0][k] + (dp[1][k + 1] != 100000 ? dp[1][k + 1] : rec(1, k + 1, mat))});
            }
            else if(k == (mat[0].size() - 1))
                ans = min({ans, mat[0][k] + (dp[1][k] != 100000 ? dp[1][k] : rec(1, k, mat)), mat[0][k] + (dp[1][k - 1] != 100000 ? dp[1][k - 1] : rec(1, k + 1, mat))});
            else
            {
                for(int i = k - 1; i <= k + 1; i++)
                ans = min(ans, mat[0][k] + (dp[1][i] != 100000 ? dp[1][i] : rec(1, i, mat)));
            }
        }
        return ans;
    }
};
