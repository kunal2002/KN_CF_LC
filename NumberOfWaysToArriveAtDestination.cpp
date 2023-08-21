int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector<pair<long long,long long>> adj[n];
        for(int i = 0; i < roads.size(); i++)
        {
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        priority_queue< pair<long long,long long> , vector<pair<long long,long long>> , greater<pair<long long,long long>> > pq;
        pq.push({0, 0}); // dist, node
        vector<long long> dist(n, 1e18);
        vector<long long> ways(n, 0);
        ways[0] = 1; // only way to reach the source 
        dist[0] = 0;
        int mod = 1e9 + 7;
        while(!pq.empty())
        {
            auto ele = pq.top();
            pq.pop();
            long long steps = ele.first;
            long long node = ele.second;
            for(auto x: adj[node])
            {
                long long distance = steps + x.second;
                if(distance < dist[x.first])
                {
                    dist[x.first] = distance;
                    ways[x.first] = ways[node];
                    pq.push({distance, x.first});
                }
                else if(distance == dist[x.first])
                {
                    ways[x.first] = (ways[x.first]%mod + ways[node]%mod) % mod;   
                }
            }
        }
        return ways[n - 1];
    }
