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
    ListNode *reverseList(ListNode *head) {
        ListNode *p = NULL, *n = NULL;
        while (head) {
            n = head->next;
            head->next = p;
            p = head;
            head = n;
        }
        return p;
    }
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;
        ListNode *slow = head, *fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = reverseList(slow->next);
        slow = slow->next;
        while (slow) {
            if (head->val != slow->val)
                return false;
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
};