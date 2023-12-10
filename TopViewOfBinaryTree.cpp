class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        //Doing a level order traversal on the Tree so that the order of elements remains intact
        queue<pair<int, Node*>> q;
        vector<int> ans;
        map<int, int> mp;
        q.push({0, root});
        while(!q.empty())
        {
            int dist = q.front().first;
            Node* node = q.front().second;
            q.pop();
            if(!mp[dist])
                mp[dist] = node->data;
            if(node->left != NULL)
                q.push({dist - 1, node->left});
            if(node->right != NULL)
                q.push({dist + 1, node->right});
        }
        for(auto x : mp)
            ans.push_back(x.second);
        return ans;
    }

};
