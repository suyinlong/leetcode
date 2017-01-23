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
    int closestValue(TreeNode* root, double target) {
        int ans = root->val;
        double diff = abs(root->val * 1.0 - target);

        while (root) {
            double d = abs(root->val * 1.0 - target);
            if (d < diff) {
                ans = root->val;
                diff = d;
            }
            if (target < root->val)
                root = root->left;
            else
                root = root->right;
        }

        return ans;
    }
};