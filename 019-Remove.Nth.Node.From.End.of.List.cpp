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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head)
            return NULL;
        if (!head->next && n == 1)
            return NULL;
        ListNode *p = head, *q = head;
        for (int i = 0; i < n; i++)
            q = q->next;
        while (q && q->next) {
            p = p->next;
            q = q->next;
        }
        if (!q)
            return head->next;
        p->next = p->next->next;
        return head;

    }
};