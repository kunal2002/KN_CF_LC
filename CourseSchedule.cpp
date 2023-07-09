bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses + 1];
        vector<int> indegree(numCourses + 1);
        for(int i = 0; i < prerequisites.size(); i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            // indegree[prerequisites[i][1]]++;
        }
        for(int i = 0; i < numCourses; i++)
        {
            for(auto x : adj[i])
                indegree[x]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }
        // cout << q.front() << " ";
        vector<int> ans;
        while(!q.empty())
        {
            int ele = q.front(); 
            q.pop();
            ans.push_back(ele);
            for(auto x: adj[ele])
            {
                indegree[x]--;
                if(indegree[x] == 0)
                    q.push(x);
            }
        }
        if(ans.size() == numCourses)
            return true;
        return false;
    }
