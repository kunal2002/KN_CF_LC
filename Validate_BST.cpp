/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool check(TreeNode* root, long long mini, long long maxi)
    {
        if(root == NULL)
            return true;
        //The BST is not valid as either or both of them are breaking the rule of BST 
        // left node should have strictly less values than root
        // right node should have greater values than root
        if(root->val < mini || root->val > maxi)
            return false;
        //for a BST, we know the left node has to be smaller than root->data can't be more than that (maxi)
        bool left, right;
        left = check(root->left, mini, (long long)root->val - 1);
        // the right node has to have a minimum value of root->data or greater , maximum can be anything
        right = check(root->right,(long long) root->val + 1, maxi);
        return (left && right);

    }
    bool isValidBST(TreeNode* root) {
        return check(root,(long long) INT_MIN,(long long) INT_MAX);
    }
};
