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
    void dfs(TreeNode *root, int p, int &r) {
        if (!root) {
            r = max(r, p);
            return;
        }
        dfs(root->left, p+1, r);
        dfs(root->right, p+1, r);

    }
    int maxDepth(TreeNode* root) {
        int r = 0;
        dfs(root, 0, r);
        return r;
    }
};