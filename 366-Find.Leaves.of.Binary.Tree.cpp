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
    int dfs(TreeNode *root, vector<vector<int>> &ans) {
        if (!root) return 0;
        int left = dfs(root->left, ans);
        int right = dfs(root->right, ans);
        int t = max(left, right);
        if (ans.size() == t)
            ans.push_back(vector<int>());
        ans[t].push_back(root->val);
        return t + 1;
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(root, ans);
        return ans;
    }
};