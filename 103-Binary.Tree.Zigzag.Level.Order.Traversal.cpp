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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        vector<stack<TreeNode*>> ss(2, stack<TreeNode*>());

        ss[0].push(root);
        int k = 0;

        while (ss[k % 2].size()) {
            while (ss[k % 2].size()) {
                TreeNode *node = ss[k % 2].top();
                ss[k % 2].pop();
                if (!node) continue;
                if (ans.size() == k) ans.push_back(vector<int>());
                ans[k].push_back(node->val);
                if (k % 2 == 0) {
                    ss[(k+1) % 2].push(node->left);
                    ss[(k+1) % 2].push(node->right);
                }
                else {
                    ss[(k+1) % 2].push(node->right);
                    ss[(k+1) % 2].push(node->left);
                }
            }
            k++;
        }

        return ans;
    }
};