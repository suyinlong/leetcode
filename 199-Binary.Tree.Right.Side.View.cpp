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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (!root)
            return ans;
        int lv = 0;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));

        while (!q.empty()) {
            TreeNode *node = q.front().first;
            int l = q.front().second;
            q.pop();

            if (lv == l) {
                ans.push_back(node->val);
                lv++;
            }
            if (node->right)
                q.push(make_pair(node->right, l+1));
            if (node->left)
                q.push(make_pair(node->left, l+1));
        }
        return ans;

    }
};