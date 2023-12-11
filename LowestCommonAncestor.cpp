TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root->val == p->val || root->val == q->val)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left == NULL)  return right; //Both nodes in the right Subtree
        if(right == NULL) return left; //Both nodes in the left Subtree
        return root; // One node in the left Subtree and one in the right Subtree
    }
