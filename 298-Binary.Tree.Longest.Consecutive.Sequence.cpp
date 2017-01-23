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
    void traversal(TreeNode *root, int length, int &ans) {
        ans = max(ans, length);
        if (root->left && root->left->val - root->val == 1)
            traversal(root->left, length + 1, ans);
        else if (root->left)
            traversal(root->left, 1, ans);
        if (root->right && root->right->val - root->val == 1)
            traversal(root->right, length + 1, ans);
        else if (root->right)
            traversal(root->right, 1, ans);
    }
public:
    int longestConsecutive(TreeNode* root) {
        if (!root) return 0;
        int ans = 1;
        traversal(root, 1, ans);
        return ans;
    }
};