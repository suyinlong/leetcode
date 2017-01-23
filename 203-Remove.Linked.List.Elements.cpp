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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummyHead(0);
        ListNode *p = &dummyHead;

        while (head) {
            if (head->val != val) {
                p->next = head;
                p = p->next;
            }
            head = head->next;
        }
        p->next = NULL;
        return dummyHead.next;
    }
};