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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode e(0), o(0), *ee = &e, *oo = &o;
        bool odd = true;
        while (head) {
            if (odd) {
                oo->next = head;
                oo = oo->next;
                odd = false;
            }
            else {
                ee->next = head;
                ee = ee->next;
                odd = true;
            }
            head = head->next;
        }
        ee->next = NULL;
        oo->next = e.next;
        return o.next;
    }
};