int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        if(start == end)
            return 0;
        queue<pair<int,int>> q;
        q.push({0, start});
        vector<int> dist(100000, 1e9);
        dist[start] = 0;
        int mod = 100000;
        while(!q.empty())
        {
            int steps = q.front().first;
            int newSt = q.front().second;
            q.pop();
            if(newSt == end)
            {
                return steps;
            }
            for(int i = 0; i < arr.size(); i++)
            {
                int rem = (newSt * arr[i]) % mod;
                if(dist[rem] > steps + 1)
                {
                    dist[rem] = steps + 1;
                    q.push({steps + 1, rem});
                }
            }
        }
        return -1;
    }
