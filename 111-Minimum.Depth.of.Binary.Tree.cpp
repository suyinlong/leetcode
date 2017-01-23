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
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        queue<pair<TreeNode*, int>> q;

        q.push(pair<TreeNode*, int>(root, 1));
        while (!q.empty()) {
            auto c = q.front();
            if (!c.first->left && !c.first->right)
                return c.second;
            if (c.first->left)
                q.push(pair<TreeNode*, int>(c.first->left, c.second + 1));
            if (c.first->right)
                q.push(pair<TreeNode*, int>(c.first->right, c.second + 1));
            q.pop();
        }
        return -1;
    }
};