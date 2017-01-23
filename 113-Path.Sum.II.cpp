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
    void pathSum(TreeNode *root, int sum, int p, vector<int> &current, vector<vector<int>> &ans) {
        if (!root)
            return;
        current.push_back(root->val);
        if (p + root->val == sum && !root->left && !root->right)
            ans.push_back(current);
        pathSum(root->left, sum, p + root->val, current, ans);
        pathSum(root->right, sum, p + root->val, current, ans);
        current.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> current;

        pathSum(root, sum, 0, current, ans);
        return ans;
    }
};