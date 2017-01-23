/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head)
            return NULL;
        unordered_map<RandomListNode*, RandomListNode*> copyMap;

        RandomListNode dummyHead(0);
        RandomListNode *q = &dummyHead, *p = head;

        while (p) {
            q->next = new RandomListNode(p->label);
            copyMap[p] = q->next;
            q = q->next;
            p = p->next;
        }
        p = head, q = dummyHead.next;
        while (p) {
            if (p->random) {
                auto it = copyMap.find(p->random);
                q->random = it->second;
            }
            p = p->next;
            q = q->next;
        }
        return dummyHead.next;
    }
};