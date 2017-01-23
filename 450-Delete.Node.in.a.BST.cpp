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
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;
        if (root->val < key) root->right = deleteNode(root->right, key);
        else if (root->val > key) root->left = deleteNode(root->left, key);
        else {
            if (!root->left || !root->right) {
                TreeNode *node = (!root->left) ? root->right : root->left;
                delete root;
                root = node;
            }
            else {
                TreeNode *next = root->right;
                while (next->left) next = next->left;
                root->val = next->val;
                root->right = deleteNode(root->right, root->val);
            }
        }
        return root;
    }
};