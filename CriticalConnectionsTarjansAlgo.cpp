class Solution {
    private:
    int timer = 1;
    private:
    void dfs(vector<int> adj[], int parent, vector<bool>& vis, int node, 
    vector<vector<int>>& bridges, int tin[], int low[])
    {
        vis[node] = true;
        tin[node] = low[node] = timer;
        timer++;
        for(auto x : adj[node])
        {
            if(x == parent)
                continue;
            if(!vis[x])
            {
                dfs(adj, node, vis, x, bridges, tin, low);
                //greedily takes the smallest low time for its self bcoz it is not 
                // node's parent so it has a chance of getting a path which has a 
                // node with smaller intime than it's parent so that it can travel
                // using that path to it's parent meaning graph is still in one piece
                low[node] = min(low[node], low[x]);
                // now making sure if we cut this edge loose, will it make a difference
                // if the lowest node from where it can originate is bigger than the 
                // birth/in time of the parent node means there ain't no way in hell
                // that you're gonna reach your parent any other way than the 
                // direct connection you both share
                // node tin[node]
                // |
                // |
                // x low[x]
                if(low[x] > tin[node])
                    bridges.push_back({node, x});
            }
            else
            {
                //if you've visited it, it means it's a part of your path
                // so it can never be a bridge
                low[node] = min(low[node], low[x]); 
            }

        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto x: connections)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<bool> vis(n + 1, false);
        int tin[n]; //in time
        int low[n]; // checks if the node has any connections to it's parent node via 
        // some other path other than direct connection to it's parent
        vector<vector<int>> bridges;
        dfs(adj, -1, vis, 0, bridges, tin, low);
        return bridges;
    }
};
