//Instead of visiting each node we make a sorted vector of pairs sorting them by weight for getting the MST, a DSU data structure is used which at each pair tells us
//if the two nodes already have a sorted weighted edge or not, if they don't, DSU combines it, if it is already a component of DSU means we don't need an extra 
//weight to connect it with any other node since it already is connected in the Data Structure, hence iterating over all edges in a weight-sorted manner we get 
//minimum spanning tree weight
class DisjointSet{
    vector<int> rank, parent, size;
public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for(int i = 0; i <= n; i++)
            parent[i] = i;
    }
    int findUParent(int node)
    {
        if(node == parent[node])
            return node;
        //Path Compression
        return parent[node] = findUParent(parent[node]);
    }
    void UnionbySize(int u, int v)
    {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if(ulp_u == ulp_v)
            return;
        if(rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    } 
};
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int,pair<int,int>> > edges;
        for(int i = 0; i < V; i++)
        {
            for(auto x: adj[i])
            {
                int wt = x[1];
                int adjNode = x[0];
                int node = i;
                edges.push_back({wt,{node, adjNode}});
            }
        }
        int ans = 0;
        DisjointSet ds(V);
        sort(edges.begin(), edges.end());
        for(auto x: edges)
        {
            int WT = x.first;
            int node = x.second.first;
            int adjNode = x.second.second;
            if(ds.findUParent(node) != ds.findUParent(adjNode))
            {
                ds.UnionbySize(node, adjNode);
                ans += WT;
            }
        }
        return ans;
        
    }
