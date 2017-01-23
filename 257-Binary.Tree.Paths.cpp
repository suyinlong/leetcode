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
    void dfs(TreeNode *root, vector<int> &current, vector<string> &result) {
        if (!root)
            return;
        current.push_back(root->val);
        if (!root->left && !root->right) {
            string s;
            for (int c: current)
                s += to_string(c) + "->";
            result.push_back(s.substr(0, s.length() - 2));
        }
        if (root->left)
            dfs(root->left, current, result);
        if (root->right)
            dfs(root->right, current, result);
        current.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<int> current;
        dfs(root, current, result);
        return result;
    }
};