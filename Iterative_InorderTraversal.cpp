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
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* curr = root;
        vector<int> ans;
        while(true)
        {
            if(curr != NULL)
            {
                st.push(curr);
                curr = curr->left;
            }
            else
            {
                if(st.empty())
                    break;
                auto ele = st.top();
                st.pop();
                ans.push_back(ele->val);
                curr = ele;
                curr = curr->right;
            }
        }
        return ans;
    }
};
