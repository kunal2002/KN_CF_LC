//Function to find number of strongly connected components(SCC) in the graph.
	//Kosaraju's Algorithm = 1) Find intime and outtime using dfs and stack for getting the order of the SCCs
	//2) Reverse all the edges in the graph
	//3) Do a DFS traversal on the graph and count the SCCs and store the order of nodes in the form of SCC
	void dfs(vector<int> adj[], vector<bool>& vis, int node, stack<int>& st)
	{
	    vis[node] = true;
	    for(auto x: adj[node])
	    {
	        if(!vis[x])
	        {
	            dfs(adj, vis, x, st);
	        }
	    }
	    st.push(node);
	}
    int kosaraju(int V, vector<vector<int>>& ad)
    {
        //code here
        //Calculating in-time and out-time
        vector<int> adj[V];
        for(int i = 0; i < ad.size(); i++)
        {
            for(auto x: ad[i])
                adj[i].push_back(x);
        }
        vector<bool> vis(V + 1, false);
        stack<int> st;
        for(int i = 0; i < V; i++)
        {
            if(!vis[i])
            {
                dfs(adj, vis, i, st);
            }
        }
        // Reverse the graph
        vector<int> adjT[V];
        for(int i = 0; i < V; i++)
        {
            vis[i] = false;
            vector<int> res;
            for(auto x : adj[i])
            {
                //i -> x
                //x -> i
                adjT[x].push_back(i);
            }
        }
        int scc = 0;
        stack<int> st1; // dummy stack, of no use, just passing so as to not write another dfs
        while(!st.empty())
        {
            int ele = st.top();
            st.pop();
            if(!vis[ele])
            {
                scc++;
                dfs(adjT, vis, ele, st1);
            }
        }
        return scc;
    }
