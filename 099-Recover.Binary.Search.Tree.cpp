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
    bool leftSearch(TreeNode *root, int &val, TreeNode* &n) {
        if (!root)
            return false;
        if (leftSearch(root->left, val, n))
            return true;

        if (root->val < val)
            return true;
        val = root->val;
        n = root;
        if (leftSearch(root->right, val, n))
            return true;

        return false;
    }

    bool rightSearch(TreeNode *root, int &val, TreeNode* &n) {
        if (!root)
            return false;
        if (rightSearch(root->right, val, n))
            return true;

        if (root->val > val)
            return true;
        val = root->val;
        n = root;
        if (rightSearch(root->left, val, n))
            return true;

        return false;
    }
    void recoverTree(TreeNode* root) {
        int a = INT_MIN, b = INT_MAX;
        TreeNode *n1 = NULL, *n2 = NULL;
        leftSearch(root, a, n1);
        rightSearch(root, b, n2);


        swap(n1->val, n2->val);
    }
};