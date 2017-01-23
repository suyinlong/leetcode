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
    int countNodes(TreeNode *root) {
        if (!root)
            return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        int lCount = countNodes(root->left);
        if (lCount == k-1)
            return root->val;
        else if (lCount >= k)
            return kthSmallest(root->left, k);
        else
            return kthSmallest(root->right, k - lCount - 1);

    }
};