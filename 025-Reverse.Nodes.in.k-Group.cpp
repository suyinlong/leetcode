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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        int len = 0;
        ListNode dummyHead(0);
        dummyHead.next = head;
        ListNode *cur = &dummyHead, *next, *pre = &dummyHead;
        while (cur = cur->next)
            len++;
        while (len >= k) {
            cur = pre->next;
            next = cur->next;
            for (int i = 1; i < k; i++) {
                cur->next = next->next;
                next->next = pre->next;
                pre->next = next;
                next = cur->next;
            }
            pre = cur;
            len -= k;
        }
        return dummyHead.next;
    }
};