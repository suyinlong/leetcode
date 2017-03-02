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
    int getMinimumDifference(TreeNode* root) {
        int val = -1, minDiff = INT_MAX;
        inorderTraverse(root, val, minDiff);
        return minDiff;
    }
    void inorderTraverse(TreeNode *root, int &val, int &minDiff) {
        if (root->left) inorderTraverse(root->left, val, minDiff);
        if (val >= 0) minDiff = min(minDiff, root->val - val);
        val = root->val;
        if (root->right) inorderTraverse(root->right, val, minDiff);
    }
};