// Function to detect cycle in a directed graph.
    bool dfsCheck(vector<int> adj[], int node, int Vis[], int PathVis[])
    {
        bool ans = false;
        Vis[node] = 1;
        PathVis[node] = 1;
        for(auto x: adj[node])
        {
            if(!Vis[x] && !PathVis[x])
            {
                if(dfsCheck(adj, x, Vis, PathVis))
                    return true;
            }
            else if(PathVis[x])
                return true;
        }
        PathVis[node] = 0;
        return ans;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int Vis[V + 1] = {0};
        int PathVis[V + 1] = {0};
        for(int i = 0; i < V; i++)
        {
            if(!Vis[i])
            {
                if(dfsCheck(adj, i, Vis, PathVis))
                    return true;
            }
        }
        return false;
    }
