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
    void sumLeft(TreeNode *root, int type, int &sum) {
        if (type && !root->left && !root->right) {
            sum += root->val;
            return;
        }
        if (root->left)
            sumLeft(root->left, 1, sum);
        if (root->right)
            sumLeft(root->right, 0, sum);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if (!root)
            return sum;
        sumLeft(root, 0, sum);
        return sum;
    }
};