reeNode* rec(vector<int>& nums, int s, int e)
    {
        if(s > e)
            return NULL;
        int mid = (s + e) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = rec(nums, s, mid - 1);
        root->right = rec(nums, mid + 1, e);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* ans = rec(nums, 0, (int)nums.size() - 1);
        return ans;
    }
