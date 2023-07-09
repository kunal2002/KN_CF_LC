vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool> vis(V + 1, false);
        vector<int> ans;
        stack<int> st;
        st.push(0);
        while(!st.empty())
        {
            int ele = st.top();
            st.pop();
            if(!vis[ele])
            {
                vis[ele] = true;
                ans.push_back(ele);
                for(auto x = adj[ele].end() - 1; x >= adj[ele].begin(); x--)
                {
                    if(!vis[*x])
                    {
                        st.push(*x);
                    }
                }
            }
        }
        return ans;
    }
