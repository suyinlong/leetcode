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
    ListNode* plusOne(ListNode* head) {
        if (!head)
            return NULL;
        int carry = plusOneHelper(head);
        if (carry == 1) {
            ListNode *newHead = new ListNode(1);
            newHead->next = head;
            return newHead;
        }
        return head;
    }

    int plusOneHelper(ListNode *node) {
        if (node == NULL)
            return 1;

        int carry = plusOneHelper(node->next);

        node->val += carry;
        carry = node->val / 10;
        node->val %= 10;
        return carry;
    }
};