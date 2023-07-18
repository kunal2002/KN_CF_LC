int timer = 1;
    void dfs(int node, int parent, vector<int>& vis, vector<int>& mark, int low[], int tin[], vector<int> adj[])
    {
        vis[node] = 1;
        low[node] = tin[node] = timer;
        timer++;
        int child = 0;
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                dfs(it, node, vis, mark, low, tin, adj);
                if(low[it] >= tin[node] && parent != -1)
                    mark[node] = 1;
                low[node] = min(low[node], low[it]); 
                child++;
            }
            else
                low[node] = min(low[node], tin[it]); // because we want to see if we can go before the 
                // possible articulation point through another way, if not , it's an articulation point
        }
        //if parent has multiple children then removing it will ofc divide it into multiple components
        if(child > 1 && parent == -1)
            mark[node] = 1;
    }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<int> vis(V, 0);
        vector<int> mark(V, 0); // for marking articulation points
        int low[V], tin[V];
        for(int i = 0; i < V; i++)
        {
            if(!vis[i])
            {
                dfs(i, -1, vis, mark, low, tin, adj);
            }
        }
        vector<int> ans;
        for(int i = 0; i < V; i++)
        {
            if(mark[i] == 1)
                ans.push_back(i);
        }
        if(ans.size() == 0)
            return {-1};
        return ans;
            
    }
