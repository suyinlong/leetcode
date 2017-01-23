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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q)
            return root;
        TreeNode *n1 = lowestCommonAncestor(root->left, p, q);
        TreeNode *n2 = lowestCommonAncestor(root->right, p, q);

        if (!n1)
            return n2;
        else if (!n2)
            return n1;
        else
            return root;
    }
};