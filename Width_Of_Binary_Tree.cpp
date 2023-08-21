int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        int ans = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        while(!q.empty())
        {
            int sz = q.size();
            auto ele = q.front();
            int mini_ind = ele.second;
            int first = 0;
            int last = 0;
            for(int i = 0; i < sz; i++)
            {
                int curr = q.front().second - mini_ind;
                TreeNode* node = q.front().first;
                q.pop();
                if(i == 0)
                    first = curr;
                if(i == sz - 1)
                    last = curr;
                if(node->left != NULL)
                    q.push({node->left, (long long)curr * 2 + 1});
                if(node->right != NULL)
                    q.push({node->right, (long long)curr * 2 + 2});
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
