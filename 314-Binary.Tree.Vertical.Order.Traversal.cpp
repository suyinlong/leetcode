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
    void traversal(TreeNode *root, vector<vector<int>> &pos, vector<vector<int>> &neg) {
        if (!root) return;
        queue<TreeNode*> nodeQ;
        queue<int> idxQ;
        nodeQ.push(root);
        idxQ.push(0);

        while (!nodeQ.empty()) {
            TreeNode *node = nodeQ.front();
            int idx = idxQ.front();
            nodeQ.pop();
            idxQ.pop();
            if (idx >= 0) {
                while (pos.size() <= idx)
                    pos.push_back(vector<int>());
                pos[idx].push_back(node->val);
            }
            else {
                while (neg.size() <= -idx)
                    neg.push_back(vector<int>());
                neg[-idx].push_back(node->val);
            }
            if (node->left) {
                nodeQ.push(node->left);
                idxQ.push(idx - 1);
            }
            if (node->right) {
                nodeQ.push(node->right);
                idxQ.push(idx + 1);
            }
        }
    }
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> pos;
        vector<vector<int>> neg;
        if (!root) return pos;
        traversal(root, pos, neg);
        vector<vector<int>> ans;
        for (int i = neg.size() - 1; i > 0; i--)
            ans.push_back(neg[i]);
        for (int i = 0; i < pos.size(); i++)
            ans.push_back(pos[i]);
        return ans;
    }
};