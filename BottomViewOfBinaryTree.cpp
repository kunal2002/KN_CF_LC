class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        //Same as Top View Code , just keep updating the map if you find another value at the same 
        // horizontal distance
        vector<int> ans;
        queue<pair<int, Node*>> q;
        map<int, int> mp;
        q.push({0, root});
        while(!q.empty())
        {
            int dist = q.front().first;
            Node* node = q.front().second;
            q.pop();
            mp[dist] = node->data;
            if(node->left != NULL)
                q.push({dist - 1, node->left});
            if(node->right != NULL)
                q.push({dist + 1, node->right});
        }
        for(auto x: mp)
            ans.push_back(x.second);
        return ans;
    }
};
