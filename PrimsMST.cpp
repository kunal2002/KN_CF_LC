int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue< pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > pq;
        //distance, to
        pq.push({0, 0});
        vector<bool> vis(V + 1, false);
        int weight = 0;
        while(!pq.empty())
        {
            auto ele = pq.top();
            pq.pop();
            //if the node can be visited through a lesser weight, min heap will make sure to visit using 
            //that weight first and mark it visited so the larger weight edge doesn't make it to the mst
            int dist = ele.first;
            int node = ele.second;
            if(vis[node])
                continue;
            // add it to the mst
            vis[node] = true;
            weight += dist;
            for(auto x : adj[node])
            {
                int adjNode = x[0];
                int wt = x[1];
                if(!vis[adjNode])
                {
                    //distance, adjNode
                    pq.push({wt, adjNode});
                }
            }
        }
        return weight;
    }
