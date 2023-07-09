vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> indegree(V + 1);
	    for(int i = 0; i < V; i++)
	    {
	        for(auto x: adj[i])
	            indegree[x]++;
	    }
	    vector<int> topo;
	    queue<int> q;
	    for(int i = 0; i < V; i++)
	    {
	        if(indegree[i] == 0)
	            q.push(i);
	    }
	    while(!q.empty())
	    {
	        int ele = q.front();
	        q.pop();
	        topo.push_back(ele);
	        for(auto x : adj[ele])
	        {
	            indegree[x]--;
	            if(indegree[x] == 0)
	                q.push(x);
	        }
	    }
	    return topo;
	}
