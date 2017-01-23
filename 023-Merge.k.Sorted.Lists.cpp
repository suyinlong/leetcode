/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    struct cmp {
        bool operator() (ListNode *n1, ListNode *n2) {
            return n1->val > n2->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return NULL;
        priority_queue<ListNode*, vector<ListNode*>, cmp> queue;
        for (ListNode *head: lists)
            if (head)
                queue.push(head);

        ListNode dummyHead(0), *p = &dummyHead;
        while (!queue.empty()) {
            ListNode *q = queue.top();
            queue.pop();
            p->next = q;
            p = q;
            if (p->next)
                queue.push(p->next);
        }
        return dummyHead.next;
    }
};