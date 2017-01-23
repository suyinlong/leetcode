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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode dummyHead(0);
        dummyHead.next = head;
        ListNode *pre = &dummyHead, *cur = head, *next;
        while (cur && cur->next) {
            next = cur->next;
            cur->next = next->next;
            next->next = cur;
            pre->next = next;
            pre = cur;
            cur = pre->next;
        }
        return dummyHead.next;
    }
};