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
        ListNode dummyHead(0);
        ListNode *pre = &dummyHead;
        ListNode *p = head;
        while (p) {
            ListNode *pn = p->next;
            if (pn && pn->val == p->val) {
                while (pn && p->val == pn->val)
                    pn = pn->next;
                p = pn;

            }
            else {
                pre->next = p;
                p = p->next;
                pre = pre->next;
            }
        }
        pre->next = NULL;
        return dummyHead.next;
    }
};