vector<pair<int,int>> adj[n + 1];
        for(int i = 0; i < times.size(); i++)
        {
            adj[times[i][0]].push_back({times[i][2], times[i][1]});
            // adj[times[i][1]].push_back({times[i][2], times[i][0]}); 
        }
        vector<int> dist(n + 1, 1e9);
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        //distance , node
        //basically from k to k the distance is 0
        pq.push({0, k});
        dist[k] = 0;
        dist[0] = 0; //because of 1 based indexing
        while(!pq.empty())
        {
            auto ele = pq.top();
            pq.pop();
            int distance = ele.first;
            int node = ele.second;
            //going from the present node to it's adjacent nodes and updating the minimum distance 
            for(auto x : adj[node])
            {
                if(distance + x.first < dist[x.second])
                {
                    dist[x.second] = distance + x.first;
                    pq.push({dist[x.second], x.second});
                }
            }
        }
        //the maximum distance from source node is the minimum time for signal to reach 
        // ALL the signals as if the signal reach the farthest then it must have reached
        // all others before
        int ans = *max_element(dist.begin(), dist.end());
        if(ans == 1e9)
            return -1;
        return ans;
    }
