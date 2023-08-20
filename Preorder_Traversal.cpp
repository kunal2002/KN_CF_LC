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
//  if(root == NULL)
//             return {};
//         ans.push_back(root->val);
//         preorderTraversal(root->left);
//         preorderTraversal(root->right);
class Solution {
public:
    vector<int> ans;
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        if(root == NULL)
            return {};
        st.push(root);
        TreeNode* curr = root;
        vector<int> ans;
        while(!st.empty())
        {
            auto ele = st.top();
            st.pop();
            ans.push_back(ele->val);
            if(ele->left != NULL)
                st.push(ele->left);
            if(ele->right != NULL)
                st.push(ele->right);
        }
        return ans;
    }
};
