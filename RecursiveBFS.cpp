void bfs(vector<int> adj[], vector<bool>& vis, vector<int>& ans, queue<int>& q)
    {
        if(q.empty())
        return;
        int ele = q.front();
        q.pop();
        for(auto x: adj[ele])
        {
            if(!vis[x])
            {
                vis[x] = true;
                ans.push_back(x);
                q.push(x);
            }
        }
        bfs(adj, vis, ans, q);
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool> vis(V + 1, false);
        vector<int> ans;
        queue<int> q;
        ans.push_back(0);
        q.push(0);
        bfs(adj, vis, ans, q);
        return ans;
    }
