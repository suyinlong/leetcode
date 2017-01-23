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
    int dfs(TreeNode *root, int p, unordered_map<int, int> &data) {
        if (!root) return 0;
        if (data.count(p))
            return data.find(p)->second;

        // root is not picked
        int a = dfs(root->left, p << 1, data);
        int b = dfs(root->right, (p << 1) + 1, data);

        // root is picked
        int c = (root->left) ? dfs(root->left->left, p << 2,data) + dfs(root->left->right, (p << 2) + 1, data) : 0;
        int d = (root->right) ? dfs(root->right->left, ((p << 1) + 1) << 1, data) + dfs(root->right->right, (((p << 1) + 1) << 1) + 1, data) : 0;

        int e = max(a+b, c+d+root->val);
        data[p] = e;
        return e;
    }
    int rob(TreeNode* root) {
        unordered_map<int, int> data;
        return dfs(root, 1, data);
    }
};