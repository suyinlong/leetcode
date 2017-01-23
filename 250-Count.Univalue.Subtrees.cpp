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
    int countHelper(TreeNode *root, int &subMin, int &subMax) {
        int count = 0;
        int lMin = INT_MAX, lMax = INT_MIN, rMin = INT_MAX, rMax = INT_MIN;

        if (root->left)
            count += countHelper(root->left, lMin, lMax);
        if (root->right)
            count += countHelper(root->right, rMin, rMax);
        subMin = (min(lMin, rMin) == INT_MAX) ? root->val : min(root->val, min(lMin, rMin));
        subMax = (max(lMax, rMax) == INT_MIN) ? root->val : max(root->val, max(lMax, rMax));
        if (subMin == root->val && subMax == root->val)
            return count + 1;
        else
            return count;
    }
public:
    int countUnivalSubtrees(TreeNode* root) {
        if (!root)
            return 0;
        int a, b;
        return countHelper(root, a, b);
    }
};