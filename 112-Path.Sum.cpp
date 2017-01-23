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
    bool dfs(TreeNode *root, int t) {
        if (!root->left && !root->right && t == root->val)
            return true;

        if (root->left && dfs(root->left, t - root->val))
            return true;
        if (root->right && dfs(root->right, t - root->val))
            return true;
        return false;
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root)
            return false;
        return dfs(root, sum);
    }
};