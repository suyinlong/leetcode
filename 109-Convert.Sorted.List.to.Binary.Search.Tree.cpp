/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode *buildBST(ListNode *head, ListNode *tail) {
        if (head == tail)
            return NULL;
        ListNode *mid = head, *probe = head;
        while (probe != tail && probe->next != tail) {
            mid = mid->next;
            probe = probe->next->next;
        }
        TreeNode *root = new TreeNode(mid->val);
        root->left = buildBST(head, mid);
        root->right = buildBST(mid->next, tail);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return buildBST(head, NULL);
    }
};