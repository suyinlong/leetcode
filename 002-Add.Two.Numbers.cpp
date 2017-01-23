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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode dummyNode(0);
        ListNode *p = &dummyNode;
        int carry = 0;

        while (l1 || l2) {
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;
            int c = (a + b + carry) % 10;
            carry = (a + b + carry) / 10;
            ListNode *q = new ListNode(c);
            p->next = q;
            p = p->next;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }

        if (carry > 0) {
            ListNode *q = new ListNode(carry);
            p->next = q;
        }

        return dummyNode.next;
    }
};