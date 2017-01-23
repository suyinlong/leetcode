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
    ListNode* sortList(ListNode* head) {
        if (!head)
            return NULL;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (slow->next == NULL)
            return head;
        fast = slow->next;
        slow->next = NULL;
        slow = head;
        ListNode *l1 = sortList(slow);
        ListNode *l2 = sortList(fast);
        return mergeList(l1, l2);
    }
    ListNode *mergeList(ListNode *h1, ListNode *h2) {
        if (!h1) return h2;
        if (!h2) return h1;
        ListNode dummyHead(0), *p = &dummyHead;
        while (h1 && h2) {
            if (h1->val < h2->val) {
                p->next = h1;
                p = p->next;
                h1 = h1->next;
            }
            else {
                p->next = h2;
                p = p->next;
                h2 = h2->next;
            }
        }
        if (h1)
            p->next = h1;
        if (h2)
            p->next = h2;
        return dummyHead.next;
    }
};