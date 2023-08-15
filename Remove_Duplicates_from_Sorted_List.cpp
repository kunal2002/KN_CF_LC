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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* prev = head;
        ListNode* ans = head;
        head = head->next;
        while(head != NULL)
        {
            if(head->val == prev->val)
            {
                if(head->next != NULL)
                {
                    prev->next = head->next;
                }
                else
                    prev->next = NULL;
            }
            else
                prev = head;
            head = head->next;
        }
        return ans;
    }
};
