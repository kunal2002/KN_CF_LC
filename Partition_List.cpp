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
    ListNode* partition(ListNode* head, int x) {
        ListNode* curr = head;
        ListNode* lessHead = new ListNode(0);
        ListNode* less = lessHead;
        
        ListNode* moreHead = new ListNode(0);
        ListNode* more = moreHead;

        while(curr != NULL)
        {
            if(curr->val < x)
            {
                less->next = new ListNode(curr->val);
                less = less->next;
            }
            else
            {
                more->next = new ListNode(curr->val);
                more = more->next;
            }
            curr = curr->next;
        }
        more->next = NULL;
        moreHead = moreHead->next; // 1st value was 0
        // lessHead = lessHead->next; // 1st value was 0
        less->next = moreHead;
        return lessHead->next;
    }
};
