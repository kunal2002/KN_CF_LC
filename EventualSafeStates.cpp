bool dfs(int node, vector<int> adj[], vector<bool>& vis, vector<bool>& pathVis, vector<int>& mark)
    {
        vis[node] = pathVis[node] = true;
        for(auto x: adj[node])
        {
            if(!vis[x])
            {
                if(dfs(x, adj, vis, pathVis, mark) == true)
                    return true;
            }
            else if(pathVis[x])
                return true;
        }
        mark[node] = 1;
        pathVis[node] = false;
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<bool> vis(V, false);
        vector<bool> pathVis(V, false);
        vector<int> mark(V, 0);
        for(int i = 0; i < V; i++)
        {
            if(!vis[i])
            {
                bool hey = dfs(i, adj, vis, pathVis, mark);
            }
        }
        vector<int> ans;
        for(int i = 0; i < V; i++)
        {
            if(mark[i])
                ans.push_back(i);
        }
        return ans;
    }
