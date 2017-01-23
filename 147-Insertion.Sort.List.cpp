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
    ListNode* insertionSortList(ListNode* head) {
        if (!head)
            return NULL;
        ListNode dummyHead(0), *p = &dummyHead;
        while (head) {
            ListNode *q = p;
            while (q->next && head->val > q->next->val)
                q = q->next;
            ListNode *hnext = head->next;
            head->next = q->next;
            q->next = head;
            head = hnext;
        }
        return dummyHead.next;
    }
};