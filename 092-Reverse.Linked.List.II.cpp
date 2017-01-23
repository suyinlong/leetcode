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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n)
            return head;
        ListNode *firstprev, *first, *last, *lastnext;
        int pos = 0;
        ListNode *current = head, *prev = NULL;
        while (current) {
            pos++;
            if (pos == m - 1)
                firstprev = current;
            else if (pos == m)
                first = current;
            else if (pos == n) {
                last = current;
                lastnext = current->next;
            }
            ListNode *next = current->next;
            if (pos > m && pos <= n)
                current->next = prev;
            prev = current;
            current = next;
        }
        if (m == 1)
            head = last;
        else
            firstprev->next = last;
        first->next = lastnext;
        return head;
    }
};