void dfs(vector<int> adj[], int node, int vis[], stack<int>& st)
	{
	    for(auto it : adj[node])
	    {
	        if(!vis[it])
	        {
	            vis[it] = 1;
	            dfs(adj, it, vis, st);
	        }
	    }
	    st.push(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    int vis[V + 2] = {0};
	    stack<int> st;
	    vector<int> ans;
	   // st.push(0);
	    for(int i = 0; i < V; i++)
	    {
	        if(!vis[i])
	        {
	            vis[i] = 1;
	            dfs(adj, i, vis, st);
	        }
	    }
	    while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        // for(auto x : ans)
        // cout << x << " ";
	    return ans;
	}
