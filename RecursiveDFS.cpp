void dfs(vector<int> adj[], int node, vector<bool>& vis, vector<int>& ans)
    {
        for(auto x : adj[node])
        {
            if(!vis[x])
            {
                vis[x] = true;
                ans.push_back(x);
                dfs(adj, x, vis, ans);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool> vis(V + 1, false);
        vector<int> ans;
        for(int i = 0; i < V; i++)
        {
            if(!vis[i])
            {
                vis[i] = true;
                ans.push_back(i);
                dfs(adj, i, vis, ans);
            }
        }
        return ans;
    }
