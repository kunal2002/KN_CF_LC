void rec(vector<vector<int>>& mat, int i, int j, int n, vector<string>& res, string t, vector<vector<bool>>& vis)
    {
        if(i < 0 || i >= n || j < 0 || j >= n)
        {
            return;
        }
        if(mat[i][j] == 0)
        {
            return;
        }
        if(i == n - 1 && j == n - 1)
        {
            res.push_back(t);
            return;
        }
        if(!vis[i][j])
        {
            t += 'D';
            vis[i][j] = true;
            rec(mat, i + 1, j, n, res, t, vis);
            t.pop_back();
            vis[i][j] = false;
        }
        if(!vis[i][j])
        {
            t += 'R';
            vis[i][j] = true;
            rec(mat, i, j + 1, n, res, t, vis);
            t.pop_back();
            vis[i][j] = false;
        }
        if(!vis[i][j])
        {
            t += 'L';
            vis[i][j] = true;
            rec(mat, i, j - 1, n, res, t, vis);
            t.pop_back();
            vis[i][j] = false;
        }
        if(!vis[i][j])
        {
            t += 'U';
            vis[i][j] = true;
            rec(mat,i - 1, j, n, res, t, vis);
            t.pop_back();
            vis[i][j] = false;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> res;
        string what = "";
        vector<vector<bool>> vis(m.size(), vector<bool>(m[0].size(), false));
        rec(m, 0, 0, n, res, what, vis);
        return res;
    }
