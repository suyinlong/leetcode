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
    ListNode* rotateRight(ListNode* head, int k) {
        int len = 0;
        ListNode *lenHead = head;
        while (lenHead) {
            len++;
            lenHead = lenHead->next;
        }
        if (!head || !head->next || k == 0 || k % len == 0)
            return head;
        len = len - k % len;
        ListNode *p = head;
        while (p && len > 1) {
            len--;
            p = p->next;
        }
        ListNode *q = p->next;
        p->next = NULL;
        ListNode *t = q;
        while (t->next) {
            t = t->next;
        }
        t->next = head;
        return q;
    }
};