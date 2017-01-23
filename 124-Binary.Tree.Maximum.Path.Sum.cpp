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
    int maxSum(TreeNode *root, int &m) {
        if (!root)
            return 0;
        int left = maxSum(root->left, m);
        int right = maxSum(root->right, m);

        int rootValue = root->val + ((left > 0) ? left : 0) + ((right > 0) ? right : 0);
        m = max(m, rootValue);
        rootValue = root->val;
        if (left > 0 || right > 0)
            rootValue += max(left, right);
        m = max(m, rootValue);

        return rootValue;
    }
public:
    int maxPathSum(TreeNode* root) {
        int curMAX = INT_MIN;
        maxSum(root, curMAX);
        return curMAX;
    }
};