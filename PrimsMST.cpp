//prims basically goes to one node and then visits all it's adjacent nodes, now whichever node can be visited with the least weight of them all shall be considered
//because we are pulling the edges out from the minimum heap and so what it basically does is, visits them at the point when it's popping them out and again 
//visits all it's adjacent nodes whichever ones are not visited they are pushed into the min heap , this goes on and on untill all nodes are visited and then we 
// get our minimum spanning tree
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
