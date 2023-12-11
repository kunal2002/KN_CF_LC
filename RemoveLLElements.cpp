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
    ListNode* removeElements(ListNode* head, int val) {
        while(head != NULL && head->val == val)
            head = head->next;
        ListNode* prev = head;
        while(prev != NULL)
        {
            while(prev->next != NULL && prev->next->val == val)
                prev->next = prev->next->next;
            prev = prev->next;
        }
        return head;
    }
};
