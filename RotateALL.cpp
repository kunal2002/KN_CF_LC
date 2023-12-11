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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)   return NULL;
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL)
        {
            len++;
            temp = temp->next;
        }
        if(k == len)
            return head;
        k = (k % len);
        len -= (k + 1);
        temp = head;
        while(temp != NULL && len > 0)
        {
            len--;
            temp = temp->next;
        }
        ListNode* rot;
        if(temp->next != NULL)
            rot = temp->next;
        else
            return head;
        ListNode* ans = rot;
        temp->next = NULL;
        while(rot->next != NULL)
            rot = rot->next;
        rot->next = head;
        return ans;
    }
};
