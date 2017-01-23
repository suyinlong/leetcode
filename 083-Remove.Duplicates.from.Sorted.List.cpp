/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return NULL;
        ListNode *p = head, *q = head;

        while (q) {
            while (q && q->val == p->val)
                q = q->next;
            p->next = q;
            p = p->next;
        }
        return head;
    }
};