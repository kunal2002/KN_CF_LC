bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> vis(V + 1);
        for(int i = 0; i < V; i++)
        {
            if(!vis[i])
            {
                queue<pair<int,int>> q;
                q.push({i, -1});
                vis[i] = true;
                while(!q.empty())
                {
                    auto ele = q.front();
                    q.pop();
                    int node = ele.first;
                    int parent = ele.second;
                    for(auto x: adj[node])
                    {
                        if(!vis[x])
                        {
                            vis[x] = true;
                            q.push({x, node});
                        }
                        else
                        {
                            //if the adjacency list has the node visited then either must be parent
                            //or if it is not a parent, then it must be a cycle
                            //because someone else also visited it
                            if(parent != x)
                                return true;
                        }
                    }
                }   
            }
        }
        
        return false;
    }
