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
    void dfs(TreeNode *root, int c, int &sum) {
        if (!root)
            return;
        c = c * 10 + root->val;
        if (!root->left && !root->right) {
            sum += c;
            return;
        }
        if (root->left)
            dfs(root->left, c, sum);
        if (root->right)
            dfs(root->right, c, sum);

    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        dfs(root, 0, sum);
        return sum;
    }
};