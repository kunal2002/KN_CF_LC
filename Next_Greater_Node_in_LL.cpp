/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> vec;
        ListNode* root = head;
        while(root != NULL)
        {
            vec.push_back(root->val);
            root = root->next;
        }
        int n = vec.size();
        vector<int> ans(n, 0);
        stack<int> st;
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && vec[st.top()] < vec[i])
            {
                ans[st.top()] = vec[i];
                st.pop();
            }
            st.push(i);
        }
        vec[n - 1] = 0;
        return ans;
    }
};
