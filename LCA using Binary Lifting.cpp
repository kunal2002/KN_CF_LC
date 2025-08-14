/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 struct BinaryLifter {
    int n, LOG;
    int root;
    vector<vector<int>> up;   // up[u][i] = 2^i-th ancestor, or -1
    vector<int> depth;        // depth from root
    vector<vector<int>> g;    // adjacency list

    BinaryLifter(int N) : n(N), g(n) {}

    void add_edge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    void preprocess(int R = 0) {
        root = R;
        LOG = 1;
        while ((1 << LOG) <= n) LOG++;
        up.assign(n, vector<int>(LOG, -1));
        depth.assign(n, 0);

        function<void(int,int)> dfs = [&](int u, int p) {
            up[u][0] = p;
            for (int i = 1; i < LOG; i++) {
                int mid = up[u][i-1];
                up[u][i] = (mid == -1) ? -1 : up[mid][i-1];
            }
            for (int v : g[u]) if (v != p) {
                depth[v] = depth[u] + 1;
                dfs(v, u);
            }
        };
        dfs(root, -1);
    }

    int kth_ancestor(int u, long long k) const {
        for (int i = LOG - 1; i >= 0 && u != -1; --i) {
            if (k & (1LL << i)) u = up[u][i];
        }
        return u; // -1 if none
    }

    int lca(int a, int b) const {
        if (a == -1 || b == -1) return a ^ b;
        if (depth[a] < depth[b]) swap(a, b);
        int diff = depth[a] - depth[b];
        a = kth_ancestor(a, diff);
        if (a == b) return a;
        for (int i = LOG - 1; i >= 0; --i) {
            if (up[a][i] != up[b][i]) {
                a = up[a][i];
                b = up[b][i];
            }
        }
        return up[a][0];
    }
};
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;
        function<int(TreeNode*)> countNodes = [&] (TreeNode* node) {
            if(!node)
                return 0;
            return 1 + countNodes(node->left) + countNodes(node->right);
        };
        int n = countNodes(root);
        unordered_map<TreeNode*, int> mp;
        vector<TreeNode*> revId(n, NULL);
        int cnt = 0;
        function<void(TreeNode*)> assignId = [&](TreeNode* node) {
            if(!node)   return;
            mp[node] = cnt;
            revId[cnt] = node;
            cnt++;
            assignId(node->left);
            assignId(node->right);
        };
        assignId(root);
        BinaryLifter bin(n);
        function<void(TreeNode*)> connectEdges = [&] (TreeNode* node) {
            if(!node)
                return;
            int uid = mp[node];
            if(node->left)
            {
                int v = mp[node->left];
                bin.add_edge(uid, v);
                connectEdges(node->left);
            }
            if(node->right)
            {
                int v = mp[node->right];
                bin.add_edge(uid, v);
                connectEdges(node->right);
            }
        };
        connectEdges(root);
        int root_id = mp[root];
        bin.preprocess(root_id);
        int pid = mp[p], qid = mp[q];
        int ans = bin.lca(pid, qid);
        return (ans == -1 ? NULL : revId[ans]);
    }
};
