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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (!root)
            return result;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));

        while (!q.empty()) {
            TreeNode *node = q.front().first;
            int level = q.front().second;
            q.pop();
            if (result.size() == level)
                result.push_back(vector<int>());
            result[level].push_back(node->val);
            if (node->left)
                q.push(make_pair(node->left, level + 1));
            if (node->right)
                q.push(make_pair(node->right, level + 1));
        }
        reverse(result.begin(), result.end());
        return result;
    }
};