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
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;

        ListNode *pre = NULL, *next = NULL;
        while (fast) {
            next = fast->next;
            fast->next = pre;
            pre = fast;
            fast = next;
        }

        ListNode dummyNode(0);
        ListNode *p = &dummyNode;
        while (head) {
            p->next = head;
            p = p->next;
            head = head->next;
            if (pre) {
                p->next = pre;
                p = p->next;
                pre = pre->next;
            }
        }
        p->next = NULL;

    }
};