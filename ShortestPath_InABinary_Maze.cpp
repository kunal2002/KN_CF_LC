int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int n = grid.size(); 
        int m = grid[0].size();
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>> > pq;
        pq.push({0, source});
        vector<vector<int>> dist(n , vector<int>(m , 1e9));
        dist[source.first][source.second] = 0;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = { 0, -1, 0, 1};
        while(!pq.empty())
        {
            auto ele = pq.top();
            pq.pop();
            int steps = ele.first;
            int row = ele.second.first;
            int col = ele.second.second;
            if(row == destination.first && col == destination.second)
                return steps;
            
            for(int i = 0; i < 4; i++)
            {
                int newr = row + dr[i];
                int newc = col + dc[i];
                if(newr >= 0 && newc >= 0 && newr < n && newc < m && grid[newr][newc] == 1)
                {
                    if(dist[newr][newc] > steps + 1)
                    {
                        dist[newr][newc] = steps + 1;
                        pq.push({steps + 1, {newr, newc}});
                    }
                }
            }
        }
        return -1;
    }
