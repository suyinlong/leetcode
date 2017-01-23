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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB)
            return NULL;
        ListNode *pA = headA, *pB = headB;
        while (pA != pB) {
            pA = pA->next;
            pB = pB->next;
            if (pA == pB)
                return pA;
            if (!pA)
                pA = headB;
            if (!pB)
                pB = headA;
        }
        return pA;
    }
};