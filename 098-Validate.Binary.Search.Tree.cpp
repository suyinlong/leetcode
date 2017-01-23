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
    bool inorderTraversal(TreeNode *root, long long &value) {
        if (root->left)
            if (!inorderTraversal(root->left, value))
                return false;
        if (root->val <= value)
            return false;
        value = root->val;
        if (root->right)
            if (!inorderTraversal(root->right, value))
                return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        long long value = LLONG_MIN;
        return inorderTraversal(root, value);
    }
};