void dfs(vector<vector<int>>& grid, int i, int j, int n, int m, vector<vector<int>>& vis, int dc[], int dr[])
    {
        vis[i][j] = 1;
        for(int k = 0; k < 4; k++)
        {
            if(dr[k] + i < n && dr[k] + i >= 0 && dc[k] + j < m && dc[k] + j >= 0)
            {
                if(!vis[dr[k] + i][dc[k] + j] && grid[dr[k] + i][dc[k] + j] == 1)
                dfs(grid, i + dr[k], j + dc[k], n, m, vis, dc, dr);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dc[] = {1, 0, -1, 0};
        int dr[] = {0, 1, 0, -1};
        pair<int,int> pos;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                {
                    pos.first = i;
                    pos.second = j;
                    break;
                }
            }
        }
        dfs(grid, pos.first, pos.second, n, m, vis, dc, dr);
        // for(auto x : vis)
        // {
        //     for(auto y: x)
        //     cout << y << " ";
        //     cout << "\n";
        // }
        cout << "\n";
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(vis[i][j])
                {
                    q.push({i, j});
                }
            }
        }
        int cnt = 0;
        while(!q.empty())
        {
            queue<pair<int,int>> sec;
            int flag = 0;
            while(!q.empty())
            {
                auto ele = q.front();
                q.pop();
                int i = ele.first, j = ele.second;
                for(int k = 0; k < 4; k++)
                {
                    if(dr[k] + i < n && dr[k] + i >= 0 && dc[k] + j < m && dc[k] + j >= 0)
                    {
                        if(!vis[dr[k] + i][dc[k] + j] && grid[dr[k] + i][dc[k] + j] != 1)
                        {
                            vis[dr[k] + i][dc[k] + j] = 1;
                            sec.push({dr[k] + i, dc[k] + j});
                        }
                        else if(!vis[dr[k] + i][dc[k] + j] && grid[dr[k] + i][dc[k] + j] == 1)
                        {
                            flag = 1;
                            goto jump_go_brr;
                        }
                    }
                }
            }
            jump_go_brr:
            if(flag)
                break;
            q = sec;
            cnt++;
        }
        return cnt;
    }
