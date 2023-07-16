class Solution {
  public:
    void dfs(vector<int> adj[], vector<bool>& vis, int n)
    {
        vis[n] = true;
        for(auto x : adj[n])
        {
            if(!vis[x])
            {
                dfs(adj, vis, x);
            }
        }
    }
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        vector<int> adj[n + 2];
        for(int i = 0; i < edge.size(); i++)
        {
            adj[edge[i][0]].push_back(edge[i][1]);
            adj[edge[i][1]].push_back(edge[i][0]);
        }
        vector<bool> vis(n + 2, false);
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                cnt++;
                dfs(adj, vis, i);
            }
        }
        if(edge.size() >= n - 1)
            return cnt - 1;
        else
            return -1;
    }
};
