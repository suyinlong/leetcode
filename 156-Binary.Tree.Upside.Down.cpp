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
    TreeNode *makeTree(TreeNode *root, TreeNode *&btop) {
        btop = root;
        if (!root->left)
            return root;
        TreeNode *newLeft = root->right;
        TreeNode *oldLeft = root->left;
        root->left = NULL;
        root->right = NULL;
        TreeNode *parent = makeTree(oldLeft, btop);
        parent->left = newLeft;
        parent->right = root;
        return root;
    }
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root)
            return NULL;
        TreeNode *btop = NULL;
        makeTree(root, btop);
        return btop;
    }
};