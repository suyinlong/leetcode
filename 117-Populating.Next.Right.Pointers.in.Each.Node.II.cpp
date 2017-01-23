/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;

        TreeLinkNode *first, *current, *child;
        first = root;

        while (first) {
            current = first;
            TreeLinkNode dummy(0);
            child = &dummy;
            while (current) {
                if (current->left) {
                    child->next = current->left;
                    child = child->next;
                }
                if (current->right) {
                    child->next = current->right;
                    child = child->next;
                }
                current = current->next;
            }
            child->next = NULL;
            first = dummy.next;
        }
    }
};