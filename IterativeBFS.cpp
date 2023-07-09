vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool> vis(V + 1, false);
        vector<int> ans;
        queue<int> q;
        q.push(0);
        ans.push_back(0);
        vis[0] = true;
        while(!q.empty())
        {
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
        }
        return ans;
    }
