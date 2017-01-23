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
        int pMin = min(p->val, q->val), pMax = max(p->val, q->val);
        if (pMax < root->val)
            return lowestCommonAncestor(root->left, p, q);
        if (pMin < root->val && root->val < pMax)
            return root;
        else if (root->val < pMin)
            return lowestCommonAncestor(root->right, p, q);
        return NULL;
    }
};