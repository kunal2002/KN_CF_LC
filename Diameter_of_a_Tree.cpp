class Solution {
public:
    
    int Height(TreeNode* root, int& maxi)
    {
        if(root == NULL)
            return 0;
        int lh = Height(root->left, maxi);
        int rh = Height(root->right, maxi);
        maxi = max(maxi, lh + rh);
        return max(lh,rh) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = -1e8;
        int h = Height(root, maxi);
        return maxi;
    }
};
