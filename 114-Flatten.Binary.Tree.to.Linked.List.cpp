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
    void dfs(TreeNode *root, TreeNode* &prev) {
        if (prev)
            prev->right = root;
        if (!root)
            return;

        TreeNode *left = root->left, *right = root->right;
        prev = root;
        root->left = NULL;
        root->right = NULL;
        dfs(left, prev);
        dfs(right, prev);
    }
    void flatten(TreeNode* root) {
        TreeNode *prev = NULL;
        dfs(root, prev);


    }
};