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
    bool balanceCheck(TreeNode *root, int &h) {
        if (!root) {
            h = 0;
            return true;
        }
        int l, r;
        if (!balanceCheck(root->left, l))
            return false;
        if (!balanceCheck(root->right, r))
            return false;
        h = max(l, r) + 1;
        if ((l - r) > 1 || (l - r) < -1)
            return false;
        return true;
    }
public:
    bool isBalanced(TreeNode* root) {
        int h;
        return balanceCheck(root, h);
    }
};