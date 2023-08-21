class Solution {
public:
    void MakeParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& Parents, TreeNode* target)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            if(it->left)
            {
                Parents[it->left] = it;
                q.push(it->left);
            }
            if(it->right)
            {
                Parents[it->right] = it;
                q.push(it->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mp;
        //Tracking Parents of each node to go backwards
        MakeParent(root, mp, target);
        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target] = true;
        int curr_level = 0;
        while(!q.empty())
        {
            int sz = q.size();
            if(curr_level == k)
                break;
            for(int i = 0; i < sz; i++)
            {
                auto it = q.front(); q.pop();
                if(it->left && !vis[it->left])
                {
                    q.push(it->left);
                    vis[it->left] = true;
                }
                if(it->right && !vis[it->right])
                {
                    q.push(it->right);
                    vis[it->right] = true;
                }
                if(mp[it] && !vis[mp[it]])
                {
                    q.push(mp[it]);
                    vis[mp[it]] = true;
                }
            }
            curr_level++;
        }
        vector<int> ans;
        while(!q.empty())
        {
            TreeNode* Node = q.front(); q.pop();
            ans.push_back(Node->val);
        }
        return ans;
    }
};
